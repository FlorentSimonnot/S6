DROP TRIGGER IF EXISTS maj_points ON contient;
DROP TRIGGER IF EXISTS plafond_points ON fidelite;

CREATE OR REPLACE FUNCTION update_fidelite() RETURNS trigger AS $$
DECLARE client client%ROWTYPE;
DECLARE facture facture%ROWTYPE;
DECLARE fidelite fidelite%ROWTYPE;
BEGIN 
	SELECT * INTO facture FROM facture WHERE idfac = NEW.idfac;
	IF NOT FOUND THEN RAISE EXCEPTION 'Facture non existante'; END IF;

	SELECT numcli INTO client FROM facture WHERE idfac = NEW.idfac;

	SELECT * INTO fidelite FROM fidelite WHERE numcli = client.numcli;
	IF NOT FOUND THEN 
		INSERT INTO fidelite VALUES ( (SELECT MAX(numcarte) FROM fidelite) + 1, current_date, NEW.prixunit * NEW.quantite, client.numcli, facture.idmag);
		RETURN NEW;
	END IF; 

	UPDATE fidelite set points = points + NEW.prixunit * NEW.quantite WHERE numcli = client.numcli and idmag = facture.idmag;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION plafond_points() RETURNS trigger AS $$
BEGIN 
	IF NEW.points >= 1000 THEN
		NEW.points = 1000; 
	END IF; 
	RETURN NEW;
END; 
$$ LANGUAGE plpgsql;

CREATE TRIGGER maj_points BEFORE INSERT ON contient
	FOR EACH ROW EXECUTE PROCEDURE update_fidelite();

CREATE TRIGGER plafond_points BEFORE INSERT OR UPDATE ON fidelite 
	FOR EACH ROW EXECUTE PROCEDURE plafond_points();

