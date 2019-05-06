#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Implémentation d'un graphe à l'aide d'une matrice d'adjacence. Les n sommets
sont identifiés par de simples naturels (0, 1, 2, ..., n-1)."""
import os

class MatriceAdjacence(object):
    def __init__(self, num=0):
        """Initialise un graphe sans arêtes sur num sommets.

        >>> G = MatriceAdjacence()
        >>> G._matrice_adjacence
        []
        """
        self._matrice_adjacence = [[0] * num for _ in range(num)]

    def ajouter_arete(self, source, destination):
        """Ajoute l'arête {source, destination} au graphe, en créant les
        sommets manquants le cas échéant.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_arete(1,2)
        >>> G.ajouter_arete(0,3)
        >>> G._matrice_adjacence
        [[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]]
        """
        if source >= self.nombre_sommets() : #créer le sommet source
            for i in range(self.nombre_sommets(), source+1) : 
                self.ajouter_sommet()
        if destination >= self.nombre_sommets() : #créer le sommet destination
            for j in range(self.nombre_sommets(), destination+1) : 
                self.ajouter_sommet()
        
        self._matrice_adjacence[source][destination] = 1
        self._matrice_adjacence[destination][source] = 1

    def afficher_matrice(self) : 
        """Affiche la matrice adjacente sous la forme d'une vraie matrice 
        (Ligne x colonne)
        """
        print("       ", end='')
        for u in range(self.nombre_sommets()) : 
            print(str(u) + "", end=' ')
        print("\n       -------------------")
        for i in range(self.nombre_sommets()) : 
            print(str(i) + "  |  ", end=' ')
            for j in range(self.nombre_sommets()) : 
                print(self._matrice_adjacence[i][j], end=' ')
            print(" ")

    def ajouter_aretes(self, iterable):
        """Ajoute toutes les arêtes de l'itérable donné au graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples de naturels.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0,1), (0,2), (1,1), (2,2)])
        >>> G._matrice_adjacence
        [[0, 1, 1], [1, 1, 0], [1, 0, 1]]
        """
        for i, j in iterable : 
            self.ajouter_arete(i, j)

    def ajouter_sommet(self):
        """Ajoute un nouveau sommet au graphe et renvoie son identifiant.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G._matrice_adjacence
        [[0]]
        >>> G.ajouter_sommet()
        1
        >>> G._matrice_adjacence
        [[0, 0], [0, 0]]
        """
        taille = len(self._matrice_adjacence)
        for i in range(taille) : 
            self._matrice_adjacence[i].append(0)
        self._matrice_adjacence.append([0] * (taille+1))
        return taille

    def aretes(self):
        """Renvoie l'ensemble des arêtes du graphe sous forme de couples (si on
        les stocke sous forme de paires, on ne peut pas stocker les boucles,
        c'est-à-dire les arêtes de la forme (u, u)).
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2)])
        >>> G.aretes()
        [(0, 1), (0, 3), (1, 2), (2, 2)]
        """
        res = []
        for i in range(len(self._matrice_adjacence)) : 
            for j in range(len(self._matrice_adjacence)) : 
                if i <= j and self._matrice_adjacence[i][j] == 1 : 
                    res.append((i, j))
        return res

    def boucles(self):
        """Renvoie les boucles du graphe, c'est-à-dire les arêtes reliant un
        sommet à lui-même.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2)])
        >>> G.boucles()
        [(2, 2)]
        """
        res = []
        for i in range(len(self._matrice_adjacence)) : 
            for j in range(len(self._matrice_adjacence)) : 
                if i == j and self._matrice_adjacence[i][j] == 1 : 
                        res.append((i, j))
        return res

    def contient_arete(self, u, v):
        """Renvoie True si l'arête {u, v} existe, False sinon.
		>>> G = MatriceAdjacence()
		>>> G.ajouter_aretes([(0, 1), (2, 1), (2, 2)])
		>>> G.contient_arete(3, 3)
		False
		>>> G.contient_arete(1, 0)
		True
        """
        if not self.contient_sommet(u) or not self.contient_sommet(v) : 
        	return False
        if self._matrice_adjacence[u][v] == 1 and self._matrice_adjacence[v][u] == 1:
            return True; 
        return False;

    def contient_sommet(self, u):
        """Renvoie True si le sommet u existe, False sinon.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.contient_sommet(1)
        True
        >>> G.contient_sommet(4)
        False"""
        if self.nombre_sommets() <= u : 
            return False 
        return True

    def degre(self, sommet):
        """Renvoie le degré d'un sommet, c'est-à-dire le nombre de voisins
        qu'il possède.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0,1), (1,1), (3,2), (4,0), (1, 2)])
        >>> G.degre(1)
        4
        """
        if not self.contient_sommet(sommet) : 
        	raise Exception("Le sommet n'existe pas")
        	
        degre = 0
        for i in range(len(self._matrice_adjacence)) : 
        	if self._matrice_adjacence[sommet][i] == 1 : 
        		if i == sommet : 
        			degre += 2
        		else :  
        			degre += 1
        return degre

    def nombre_aretes(self):
        """Renvoie le nombre d'arêtes du graphe.
		>>> G = MatriceAdjacence()
		>>> G.ajouter_sommet()
		0
		>>> G.ajouter_sommet()
		1
		>>> G.ajouter_sommet()
		2
		>>> G.ajouter_sommet()
		3
		>>> G.ajouter_aretes([(0,1), (1,1), (3,2), (4,0)])
		>>> G.nombre_aretes()
		4
        """
        return len(self.aretes())

    def nombre_boucles(self):
        """Renvoie le nombre d'arêtes de la forme {u, u}.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0,1), (1,1), (3,2), (4,0)])
        >>> G.nombre_boucles()
        1
        """
        return len(self.boucles())

    def nombre_sommets(self):
        """Renvoie le nombre de sommets du graphe.
        >>> from random import randint
        >>> n = randint(0, 10)
        >>> MatriceAdjacence(n).nombre_sommets() == n
        True
        """
        return len(self._matrice_adjacence)

    def retirer_arete(self, u, v):
        """Retire l'arête {u, v} si elle existe; provoque une erreur sinon.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 2), (3, 0), (1, 1), (3, 2)])
        >>> G.retirer_arete(2, 3)
        >>> G._matrice_adjacence
        [[0, 1, 1, 1], [1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]]
        """
        if self.contient_arete(u, v) : 
            self._matrice_adjacence[u][v] = 0
            self._matrice_adjacence[v][u] = 0
        else : 
            raise Exception("L'arête n'existe pas")

    def retirer_aretes(self, iterable):
        """Retire toutes les arêtes de l'itérable donné du graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples d'éléments (quel que soit le type du couple).
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 2), (3, 0), (1, 1), (3, 2)])
        >>> G.retirer_aretes([(2, 3), (0, 1)])
        >>> G._matrice_adjacence
        [[0, 0, 1, 1], [0, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]]"""
        for u, v in iterable : 
            self.retirer_arete(u, v)

    def retirer_sommet(self, sommet):
        """Déconnecte un sommet du graphe et le supprime.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2), (3,1)])
        >>> G._matrice_adjacence
        [[0, 1, 0, 1], [1, 0, 1, 1], [0, 1, 1, 0], [1, 1, 0, 0]]
        >>> G.retirer_sommet(2)
        >>> G._matrice_adjacence
        [[0, 1, 1], [1, 0, 1], [1, 1, 0]]
        """
        if not self.contient_sommet(sommet) : 
            raise Exeception("Erreur, le sommet , n'existe pas")

        #Retirer les aretes liées
        for v in self.voisins(sommet) : 
            self.retirer_arete(sommet, v)  

        del self._matrice_adjacence[sommet] #supprimer la ligne sommet

        for i in range(len(self._matrice_adjacence)) : 
            del self._matrice_adjacence[i][sommet] #supprimer la colonne sommet
                
    def retirer_sommets(self, iterable):
        """Efface les sommets de l'itérable donné du graphe, et retire toutes
        les arêtes incidentes à ces sommets.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2), (3,1)])
        >>> G._matrice_adjacence
        [[0, 1, 0, 1], [1, 0, 1, 1], [0, 1, 1, 0], [1, 1, 0, 0]]
        >>> G.retirer_sommets([2, 0])
        >>> G._matrice_adjacence
        [[0, 1], [1, 0]]
        """
        for sommet in iterable : 
            self.retirer_sommet(sommet)

    def sommets(self):
        """Renvoie l'ensemble des sommets du graphe.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2)])
        >>> G.sommets()
        [0, 1, 2, 3]"""
        sommets = []
        for i in range(len(self._matrice_adjacence)) : 
            sommets.append(i)
        return sommets

    def sous_graphe_induit(self, iterable):
        """Renvoie le sous-graphe induit par l'itérable de sommets donné.
        >>> aretes = [(0,1), (3,2), (5,6), (4, 4), (1, 6), (2, 5), (0, 4), (0, 11)]
		>>> G = MatriceAdjacence()
		>>> G.ajouter_aretes(aretes)
		>>> print(len(G._matrice_adjacence))
		12
		>>> ss_graphe = G.sous_graphe_induit([0, 2, 4, 3])
		>>> print(ss_graphe._matrice_adjacence)
		[[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 1]]
        """
        graphe = MatriceAdjacence()

        for i in range(len(self._matrice_adjacence)) : 
        	for j in range(len(self._matrice_adjacence)) : 
        		if self._matrice_adjacence[i][j] == 1 : 
        			graphe.ajouter_arete(i, j)

        for i in range(len(graphe._matrice_adjacence)-1, 0, -1) : 
        	if i not in iterable : 
        		graphe.retirer_sommet(i)

        return graphe

    def voisins(self, sommet):
        """Renvoie la liste des voisins d'un sommet.
        >>> G = MatriceAdjacence()
        >>> G.ajouter_aretes([(0, 1), (0, 3), (2, 1), (2, 2)])
        >>> G.voisins(2)
        [1, 2]
        """
        voisins = []
        for j in range(len(self._matrice_adjacence)) :
                if self._matrice_adjacence[sommet][j] == 1 : 
                    voisins.append(j)
        return voisins


def export_dot(graphe):
    """Renvoie une chaîne encodant le graphe au format dot."""
    string = "graph graphe { "

    sommets = "\n"
    for sommet in graphe.sommets() : 
        sommets += "\t" + str(sommet) + ";\n"

    aretes = "" 
    for u, v in graphe.aretes() : 
        aretes += "\t" + str(u) + " -- " + str(v) + ";\n"

    return string + sommets + aretes + "}"

def creer_dot(graphe, fichier) : 
    string = export_dot(graphe)
    fichier = open(fichier, "w")
    fichier.write(string)
    fichier.close()


def main():
    import doctest
    doctest.testmod()


if __name__ == "__main__":
    main()
