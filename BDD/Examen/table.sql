DROP TABLE IF EXISTS appartement CASCADE; 
DROP TABLE IF EXISTS immeuble CASCADE; 
DROP TABLE IF EXISTS photo CASCADE; 
DROP TABLE IF EXISTS piece CASCADE; 

CREATE TABLE Immeuble(
    Id serial PRIMARY KEY, 
    adrNum VARCHAR (7) NOT NULL, 
    adrVoie VARCHAR (100) NOT NULL, 
    adrCodePostal VARCHAR (5) NOT NULL,  
    adrVille VARCHAR (30) NOT NULL, 
    fibreOptique boolean  NOT NULL,  
    parkingPrivatif boolean  NOT NULL
);
    
CREATE TABLE Appartement(
    immeuble integer, 
    num integer NOT NULL, 
    description TEXT, 
    loyer float NOT NULL, 
    superficie float NOT NULL, 
    terrasse boolean NOT NULL, 
    classeConso CHAR(1) NOT NULL, 
    chauffage CHAR(1) NOT NULL,
    placeParking boolean NOT NULL, 
    prixParking float,
    CONSTRAINT pk_appartement PRIMARY KEY (immeuble, num),
    CONSTRAINT fk_immeuble FOREIGN KEY (immeuble) REFERENCES Immeuble(id)
);
    
CREATE TABLE Photo(
    immeuble integer, 
    appartement integer, 
    reference integer NOT NULL,
    titre VARCHAR(75), 
    description VARCHAR(255), 
    uri VARCHAR(120) NOT NULL,
    CONSTRAINT pk_photo PRIMARY KEY (immeuble, appartement, reference),
    CONSTRAINT fk_appartement_photo FOREIGN KEY (immeuble, appartement) REFERENCES Appartement(immeuble, num) 
);
    
    
CREATE TABLE Piece(
    immeuble integer, 
    appartement integer,
    num integer NOT NULL, 
    superficie float, 
    fonction VARCHAR (30),
    CONSTRAINT pk_piece PRIMARY KEY(immeuble, appartement, num),
    CONSTRAINT fk_appartement_piece FOREIGN KEY(immeuble, appartement) REFERENCES Appartement(immeuble, num)
);

CREATE OR REPLACE VIEW parking AS 
SELECT * FROM appartement WHERE placeParking = true; 