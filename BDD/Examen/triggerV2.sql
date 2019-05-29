CREATE OR REPLACE FUNCTION maj_superficie() RETURNS TRIGGER AS $$
DECLARE appart appartement%ROWTYPE; 
BEGIN 
    IF NEW.superficie < 0 THEN 
        RAISE EXCEPTION 'superficie négative';
    END IF; 
    SELECT * INTO appart FROM appartement WHERE num = NEW.appartement;
    UPDATE appartement set superficie = superficie + NEW.superficie WHERE num = appart.num; 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 

CREATE TRIGGER ajout_piece AFTER INSERT ON piece 
FOR EACH ROW EXECUTE PROCEDURE maj_superficie(); 