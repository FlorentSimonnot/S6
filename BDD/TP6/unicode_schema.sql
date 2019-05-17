DROP TABLE IF EXISTS unicode_sans CASCADE;
DROP TABLE IF EXISTS unicode_btree CASCADE;
DROP TABLE IF EXISTS unicode_hash CASCADE;
DROP TABLE IF EXISTS unicode_both CASCADE;

CREATE TABLE unicode_sans (
  codepoint character varying(6) PRIMARY KEY,
  charname text NOT NULL,
  category character(2) NOT NULL,
  combining integer NOT NULL,
  bidi character varying(3) NOT NULL,
  decomposition text,
  "decimal" integer,
  digit integer,
  "numeric" text,
  mirrored character(1) NOT NULL,
  oldname text,
  comment text,
  uppercase character varying(6) REFERENCES unicode_sans(codepoint),
  lowercase character varying(6) REFERENCES unicode_sans(codepoint),
  titlecase character varying(6) REFERENCES unicode_sans(codepoint)
);

\copy unicode_sans FROM UnicodeData.txt DELIMITER ';' NULL ''


-- 1/
-- uppercase donne le codepoint du caractère en majuscule si c'est une minuscule

-- 2/

-- L'index est créé quand on utilise une clé primaire car il ne faut pas de doublon 

ANALYZE unicode_sans;

SELECT relname, reltuples, relpages FROM pg_catalog.pg_class
WHERE 'unicode_sans'=relname OR 'unicode_sans_pkey'=relname;

-- La table et son index on autant d'enregistrements mais l'index prend moins de pages

CREATE TABLE unicode_btree (
  codepoint character varying(6) PRIMARY KEY,
  charname text NOT NULL,
  category character(2) NOT NULL,
  combining integer NOT NULL,
  bidi character varying(3) NOT NULL,
  decomposition text,
  "decimal" integer,
  digit integer,
  "numeric" text,
  mirrored character(1) NOT NULL,
  oldname text,
  comment text,
  uppercase character varying(6) REFERENCES unicode_btree(codepoint),
  lowercase character varying(6) REFERENCES unicode_btree(codepoint),
  titlecase character varying(6) REFERENCES unicode_btree(codepoint)
);

CREATE INDEX charname_btree_seq ON unicode_btree USING btree (charname);
CREATE INDEX numeric_btree_seq ON unicode_btree USING btree (numeric);

\copy unicode_btree FROM UnicodeData.txt DELIMITER ';' NULL ''

CREATE TABLE unicode_hash (
  codepoint character varying(6) PRIMARY KEY,
  charname text NOT NULL,
  category character(2) NOT NULL,
  combining integer NOT NULL,
  bidi character varying(3) NOT NULL,
  decomposition text,
  "decimal" integer,
  digit integer,
  "numeric" text,
  mirrored character(1) NOT NULL,
  oldname text,
  comment text,
  uppercase character varying(6) REFERENCES unicode_hash(codepoint),
  lowercase character varying(6) REFERENCES unicode_hash(codepoint),
  titlecase character varying(6) REFERENCES unicode_hash(codepoint)
);

CREATE INDEX charname_hash_seq ON unicode_hash USING hash (charname);
CREATE INDEX numeric_hash_seq ON unicode_hash USING hash (numeric);

\copy unicode_hash FROM UnicodeData.txt DELIMITER ';' NULL ''


-- 3/
-- btree>hash>sans_index
-- car l'algo pour faire un btree est plus complexe qu'une table de hash

-- 4/

ANALYZE unicode_sans;
ANALYZE unicode_btree;
ANALYZE unicode_hash;

SELECT relname, reltuples, relpages FROM pg_catalog.pg_class
WHERE 'unicode_sans_pkey'=relname
  OR 'charname_btree_seq'=relname OR 'numeric_btree_seq'=relname
  OR 'charname_hash_seq'=relname OR 'numeric_hash_seq'=relname;

-- btree prend plus de blocs que hash car le codage est plus lourd
-- charname prend plus de blocs que numeric car numeric ne contient que les chiffre de 0 a 9
-- alors que charname contient le nom de tous les caractères

---- Exo 2:

CREATE TABLE unicode_both (
  codepoint character varying(6) PRIMARY KEY,
  charname text NOT NULL,
  category character(2) NOT NULL,
  combining integer NOT NULL,
  bidi character varying(3) NOT NULL,
  decomposition text,
  "decimal" integer,
  digit integer,
  "numeric" text,
  mirrored character(1) NOT NULL,
  oldname text,
  comment text,
  uppercase character varying(6) REFERENCES unicode_both(codepoint),
  lowercase character varying(6) REFERENCES unicode_both(codepoint),
  titlecase character varying(6) REFERENCES unicode_both(codepoint)
);

CREATE INDEX charname_btree_both_seq ON unicode_both USING btree (charname);
CREATE INDEX numeric_btree_both_seq ON unicode_both USING btree (numeric);
CREATE INDEX charname_hash_both_seq ON unicode_both USING hash (charname);
CREATE INDEX numeric_hash_both_seq ON unicode_both USING hash (numeric);

\copy unicode_both FROM UnicodeData.txt DELIMITER ';' NULL ''
NULL
-- 5/

ANALYZE unicode_sans; 
ANALYZE unicode_btree; 
ANALYZE unicode_hash; 
ANALYZE unicode_both; 
EXPLAIN SELECT * FROM unicode_sans WHERE numeric='1';
EXPLAIN SELECT * FROM unicode_both WHERE numeric='1';
EXPLAIN SELECT * FROM unicode_btree WHERE numeric='1';
EXPLAIN SELECT * FROM unicode_hash WHERE numeric='1';

-- cost : temps avant le renvoi du premier enregistrement puis temps total pour tout renvoyer
-- rows : nombres de lignes renvoyées
-- width : largeur (nombre de caractères) par ligne

-- Pour la table unicode_both il utilise la méthode de hash car moins couteux. 

-- 7/

SELECT count(*) FROM unicode_sans;

EXPLAIN SELECT * FROM unicode_both;
EXPLAIN SELECT * FROM unicode_sans;
EXPLAIN SELECT * FROM unicode_btree;
EXPLAIN SELECT * FROM unicode_hash;

-- C'est les mêmes temps. 
-- Il n'utilise pas les indexs pour un select *

-- 8.1/

SELECT count(*) FROM unicode_sans WHERE charname='NABLA';

EXPLAIN SELECT * FROM unicode_both WHERE charname='NABLA';
EXPLAIN SELECT * FROM unicode_sans WHERE charname='NABLA';
EXPLAIN SELECT * FROM unicode_btree WHERE charname='NABLA';
EXPLAIN SELECT * FROM unicode_hash WHERE charname='NABLA';

-- Il y a qu'un tuple correspondant à cette requete donc pas de méthode spéciale. 

-- 9.1/

SELECT count(*) FROM unicode_sans WHERE numeric<'12';

EXPLAIN SELECT * FROM unicode_both WHERE numeric<'12';
EXPLAIN SELECT * FROM unicode_sans WHERE numeric<'12';
EXPLAIN SELECT * FROM unicode_btree WHERE numeric<'12';
EXPLAIN SELECT * FROM unicode_hash WHERE numeric<'12';

-- unicod_both utilise un index scan btree car plus rapide que de chercher les valeurs dans la HashTable

-- 8.2/

SELECT count(*) FROM unicode_sans WHERE charname<'ADULT';
SELECT count(*) FROM unicode_sans WHERE charname>'ADULT';

EXPLAIN SELECT * FROM unicode_both WHERE charname<'ADULT';
EXPLAIN SELECT * FROM unicode_both WHERE charname>'ADULT';

EXPLAIN SELECT * FROM unicode_sans WHERE charname<'ADULT';
EXPLAIN SELECT * FROM unicode_sans WHERE charname>'ADULT';

EXPLAIN SELECT * FROM unicode_btree WHERE charname<'ADULT';
EXPLAIN SELECT * FROM unicode_btree WHERE charname>'ADULT';

EXPLAIN SELECT * FROM unicode_hash WHERE charname<'ADULT';
EXPLAIN SELECT * FROM unicode_hash WHERE charname>'ADULT';

--

-- 9.2/

SELECT count(*) FROM unicode_sans WHERE numeric IS NULL;
SELECT count(*) FROM unicode_sans WHERE numeric IS NOT NULL;

EXPLAIN SELECT * FROM unicode_both WHERE numeric IS NULL;
EXPLAIN SELECT * FROM unicode_both WHERE numeric IS NOT NULL;

EXPLAIN SELECT * FROM unicode_sans WHERE numeric IS NULL;
EXPLAIN SELECT * FROM unicode_sans WHERE numeric IS NOT NULL;

EXPLAIN SELECT * FROM unicode_btree WHERE numeric IS NULL;
EXPLAIN SELECT * FROM unicode_btree WHERE numeric IS NOT NULL;

EXPLAIN SELECT * FROM unicode_hash WHERE numeric IS NULL;
EXPLAIN SELECT * FROM unicode_hash WHERE numeric IS NOT NULL;

-- 

-- 10/

SELECT count(*) FROM unicode_sans WHERE charname IS NULL;
SELECT count(*) FROM unicode_sans WHERE charname IS NOT NULL;

EXPLAIN SELECT * FROM unicode_both WHERE charname IS NULL;
EXPLAIN SELECT * FROM unicode_both WHERE charname IS NOT NULL;

EXPLAIN SELECT * FROM unicode_sans WHERE charname IS NULL;
EXPLAIN SELECT * FROM unicode_sans WHERE charname IS NOT NULL;

EXPLAIN SELECT * FROM unicode_btree WHERE charname IS NULL;
EXPLAIN SELECT * FROM unicode_btree WHERE charname IS NOT NULL;

EXPLAIN SELECT * FROM unicode_hash WHERE charname IS NULL;
EXPLAIN SELECT * FROM unicode_hash WHERE charname IS NOT NULL;

-- 11/

-- EXPLAIN SELECT * FROM unicode_both WHERE charname='ADULT';
-- EXPLAIN SELECT * FROM unicode_both WHERE charname='CONTROL';

-- mauvais temps de recherche sur interval avec des hash