DROP TRIGGER IF EXISTS suppression_client on client;
DROP TRIGGER IF EXISTS maj_client on client;
DROP TRIGGER IF EXISTS demenage_magasin on magasin;

CREATE OR REPLACE FUNCTION avertissement() RETURNS trigger AS $$
DECLARE choosen_client client%ROWTYPE;
BEGIN
	IF (TG_OP = 'DELETE') THEN
		select * INTO choosen_client FROM client where numcli = OLD.numcli;
		IF NOT FOUND THEN RAISE EXCEPTION 'Client inexistant!!'; END IF;

		INSERT INTO table_log VALUES (current_date, 'W', 'Tentative de suppression du client ');
		return NULL;
	ELSIF (TG_OP = 'UPDATE') THEN 
		select * INTO choosen_client FROM client where numcli = OLD.numcli;
		IF NOT FOUND THEN RAISE EXCEPTION 'Client inexistant!!'; END IF;

		INSERT INTO table_log VALUES (current_date, 'U', 'MAJ');
		return NEW;
	END IF;

END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION demenage() RETURNS trigger AS $$
DECLARE choosen_magasin magasin%ROWTYPE;
BEGIN

	IF (OLD.ville <> NEW.ville AND OLD.nom = NEW.nom AND OLD.tel = NEW.tel AND OLD.idmag = NEW.idmag) THEN 
		INSERT INTO table_log VALUES (current_date, 'U', 'Le magasin à déménagé');
	END IF;
	return NEW;

END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER suppression_client BEFORE DELETE ON client
	FOR EACH ROW EXECUTE PROCEDURE avertissement();

CREATE TRIGGER maj_client BEFORE UPDATE ON client
	FOR EACH ROW EXECUTE PROCEDURE avertissement();

CREATE TRIGGER demenage_magasin BEFORE UPDATE ON magasin 
	FOR EACH ROW EXECUTE PROCEDURE demenage(); 
