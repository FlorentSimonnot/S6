--
--	Utilisez le script magasin_exam.sql afin de créer la base de données qui sera utilisée pour les questions suivantes.
--	Prenez le temps de vous familiariser avec les différentes tables et leur contenu avant de commencer à répondre aux questions.
--	Pour chaque question, donnez la requête SQL permettant d'obtenir le résultat demandé, et ajoutez en commentaire le nombre de lignes renvoyé par cette requête.
--  Soignez la présentation (indentation, nom des variables, etc.) de vos requêtes. La lisibilité de votre travail sera prise en compte.
--	A la fin du TP, déposez votre fichier sur elearning dans l'espace dédié à votre groupe.
--  Pensez à enregistrer régulièrement votre travail afin de ne pas le perdre en cas de panne.
--


--1. La liste de tous les clients, avec tous leurs attributs.
SELECT * FROM client;

--2. La liste des villes où il y a un client, sans doublons.
SELECT DISTINCT ville FROM client; 

--3. La liste des identifiants des produits qui sont des souris vertes.
SELECT idpro FROM produit WHERE libelle = 'souris' and couleur = 'vert';

--4. La liste des identifiants de produits qui ont été vendus à plus de 100 euros.
SELECT * FROM contient WHERE prixunit > 100;

--5. La liste des cartes de fidélité (numcarte) qui ont été créées en 2017.
SELECT numcarte FROM fidelite WHERE datecreation BETWEEN '2017-01-01' AND '2017-12-31';

--6. La liste des magasins (idmag, nom) qui ont au moins un bureau en stock.
SELECT m.idmag, m.nom  FROM magasin m, stocke s, produit p WHERE m.idmag = s.idmag and p.idpro = s.idpro and p.libelle = 'bureau';

--7. Les numéros et noms des clients qui ont la carte de fidélité d'un magasin qui n'est pas dans la ville où ils habitent.
SELECT c.numcli, c.nom FROM client c, fidelite f, magasin m WHERE f.numcli = c.numcli and m.idmag = f.idmag and m.ville <> c.ville;


--8. Les identifiants des moniteurs dont on connaît la couleur.
SELECT idpro FROM produit WHERE couleur IS NOT NULL and libelle = 'moniteur';


--9. Les noms de famille que l'on trouve à la fois à Marseille et à Reims.
 SELECT nom FROM client WHERE ville = 'reims' and nom in (SELECT nom FROM client WHERE ville = 'marseille'); 


--10. Les libellés de produits que l'on trouve en blanc mais pas en noir.
SELECT DISTINCT libelle FROM produit WHERE couleur = 'blanc' and libelle not in (SELECT libelle FROM produit WHERE couleur = 'noir'); 



--11. Le nombre de clients qui habitent à Paris.



--12. La liste des villes où il y a au moins un client, avec le nombre de clients qui s'y trouvent.



--13. La liste des clients (numcli, prenom, nom) qui ont passé au moins 10 commandes, triée par nombre de commandes décroissant.



--14. La liste des clients (numcli, prénom, nom) avec pour chacun l'argent total qu'il a dépensé.



--15. La liste des paires de clients différents (numcli1, prenom1, numcli2, prenom2) qui ont créé une carte de fidélité le même jour.



--16. Les clients (numcli, prenom, nom) qui n'ont pas assez d'argent sur une de leurs cartes de fidélité pour acheter le produit le plus cher du magasin d'où provient la carte.



--17. La liste des clients (numcli) avec pour chacun le montant de la facture la moins chère qu'il a payée.



--18. Le client (numcli, prenom, nom) qui a le plus de points de fidelité, toutes cartes confondues.



--19. Les clients (numcli, prenom, nom) dont aucune facture ne coûte plus de 400 euros.



--20. Les magasins qui ont au moins un produit de chaque libellé en stock.



