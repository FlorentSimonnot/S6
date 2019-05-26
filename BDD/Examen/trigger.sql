CREATE OR REPLACE FUNCTION verif_prix_parking() RETURNS trigger as $$
    BEGIN 
        if NEW.placeParking = FALSE THEN 
            NEW.prixParking = NULL;
        END IF;
        if NEW.placeParking = True AND NEW.prixParking < 0 THEN 
            RAISE EXCEPTION 'prix négatif banane !!'; 
        END IF; 
        RETURN NEW;
    END; 
$$ LANGUAGE plpgsql ; 

CREATE OR REPLACE FUNCTION update_superficie() RETURNS trigger as $$
    DECLARE a appartement%ROWTYPE; 
    BEGIN 
        SELECT * INTO a FROM appartement WHERE num = NEW.num; 
        UPDATE appartement set superficie = a.superficie + NEW.superficie WHERE num = a.num;
        RETURN NEW; 
    END; 
$$ LANGUAGE plpgsql; 

CREATE TRIGGER verif_prix_parking BEFORE INSERT ON appartement
    FOR EACH ROW EXECUTE PROCEDURE verif_prix_parking();

CREATE TRIGGER update_superficie AFTER INSERT ON piece
    FOR EACH ROW EXECUTE PROCEDURE update_superficie(); 