DROP TRIGGER IF EXISTS verification_stock on contient;

--- Création de la fonction de trigger
CREATE OR REPLACE FUNCTION verif_stock() RETURNS trigger AS $$
DECLARE fact facture%ROWTYPE; sto stocke%ROWTYPE;
BEGIN
	select * INTO fact FROM facture where idfac = NEW.idfac;
	IF NOT FOUND THEN RAISE EXCEPTION 'facture manquante!!'; END IF;

	select * INTO sto FROM stocke where idmag = fact.idmag and idpro = NEW.idpro;
	IF NOT FOUND THEN
		RAISE NOTICE 'Produit indisponible dans le magasin %', fact.idmag;
		RETURN NULL;
	END IF;
	
	IF sto.quantite < NEW.quantite THEN 
		RAISE NOTICE 'Stock limite. Quantite ajustee a %',sto.quantite;
	        NEW.quantite=sto.quantite;
	END IF;
	UPDATE stocke SET quantite = quantite - NEW.quantite WHERE idpro=NEW.idpro and idmag = fact.idmag;
	UPDATE facture SET date = current_date WHERE idfac = NEW.idfac;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

--- Création du trigger

CREATE TRIGGER verification_stock BEFORE INSERT ON contient
	FOR EACH ROW EXECUTE PROCEDURE verif_stock();

