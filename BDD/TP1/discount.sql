DROP TRIGGER IF EXISTS view_insert_trigger ON discount;

CREATE OR REPLACE VIEW discount as
SELECT s.idpro, s.prixunit, s.quantite, p.libelle, p.couleur 
FROM stocke s, produit p WHERE s.idpro = p.idpro and 
idmag = (SELECT idmag FROM magasin WHERE nom = 'Discount' and ville = 'grenoble');

CREATE OR REPLACE FUNCTION insertion() RETURNS TRIGGER AS $$ 
DECLARE p produit%ROWTYPE;
BEGIN 

	IF (TG_OP = 'INSERT') THEN

		SELECT * INTO p FROM produit WHERE idpro = NEW.idpro;
		IF NOT FOUND THEN RAISE EXCEPTION 'Produit n existe pas'; END IF;

		IF NEW.quantite < 0 THEN RAISE EXCEPTION 'Quantité négative banane !!'; END IF;

		IF NEW.prixunit < 0 THEN RAISE EXCEPTION 'Prix négatif banane !!'; END IF;

		INSERT INTO stocke VALUES 
		(
		(SELECT idmag FROM magasin WHERE nom = 'Discount' and ville = 'grenoble'), 
		NEW.idpro, 
		NEW.prixunit, 
		NEW.quantite);
		RETURN NEW;
	ELSIF (TG_OP = 'UPDATE') THEN
		SELECT * INTO p FROM produit WHERE idpro = OLD.idpro;
		IF NOT FOUND THEN RAISE EXCEPTION 'Produit n existe pas'; END IF;

		IF NEW.quantite < 0 THEN RAISE EXCEPTION 'Quantité négative banane !!'; END IF;

		IF NEW.prixunit < 0 THEN RAISE EXCEPTION 'Prix négatif banane !!'; END IF;

		UPDATE stocke set prixunit = NEW.prixunit, quantite = NEW.quantite WHERE idpro = OLD.idpro;
		RETURN NEW;

	ELSIF (TG_OP = 'DELETE') THEN 
		DELETE FROM stocke WHERE idmag = (SELECT idmag FROM magasin WHERE nom = 'Discount' and ville = 'grenoble') and idpro = OLD.idpro;
		RETURN NULL;
	END IF;
END; 
$$ LANGUAGE plpgsql;

CREATE TRIGGER view_insert_trigger
INSTEAD OF INSERT OR UPDATE OR DELETE ON discount 
FOR EACH ROW EXECUTE PROCEDURE insertion();