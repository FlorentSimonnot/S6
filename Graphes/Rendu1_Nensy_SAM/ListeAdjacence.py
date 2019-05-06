#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Nensy SAM
"""Implémentation d'un graphe à l'aide d'une liste d'adjacence. Les n sommets
sont identifiés par de simples naturels (0, 1, 2, ..., n-1)."""
import os

class ListeAdjacence(object):
    def __init__(self, num=0):
        """Initialise un graphe sans arêtes sur num sommets.

        >>> G = ListeAdjacence()
        >>> G._liste_adjacence
        []
        """
        self._liste_adjacence = [list() for _ in range(num)]

    def ajouter_arete(self, source, destination):
        """
            Ajoute l'arête {source, destination} au graphe, en créant les
            sommets manquants le cas échéant.
            >>> G = ListeAdjacence()
            >>> G.ajouter_arete(0,1)
            >>> G.ajouter_arete(1,3)
            >>> G.ajouter_arete(2,2)
            >>> G.ajouter_arete(2,5)
            >>> G._liste_adjacence
            [[1], [0, 3], [2, 2, 5], [1], [], [2]]
        """
        if source >= self.nombre_sommets() : 
            for i in range(self.nombre_sommets(), source+1) : 
                self.ajouter_sommet()
        if destination >= self.nombre_sommets() : 
            for j in range(self.nombre_sommets(), destination+1) : 
                self.ajouter_sommet()

        if not self.contient_arete(destination, source) and not self.contient_arete(source, destination):
            self._liste_adjacence[source].append(destination)
            self._liste_adjacence[destination].append(source)

    def ajouter_aretes(self, iterable):
        """Ajoute toutes les arêtes de l'itérable donné au graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples de naturels.
        >>> G = ListeAdjacence()
        >>> G.ajouter_aretes([(0,1), (1, 3), (2,2)])
        >>> G._liste_adjacence
        [[1], [0, 3], [2, 2], [1]]
        """
        for u, v in iterable : 
            self.ajouter_arete(u, v)

    def afficher_liste(self) : 
        for i in range(len(self._liste_adjacence)) : 
            print(str(i) + " -> ", end=' ')
            for j in self._liste_adjacence[i] : 
                print(str(j) + " -- ", end =' ')
            print("end")

    def ajouter_sommet(self):
        """Ajoute un nouveau sommet au graphe et renvoie son identifiant.

        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G._liste_adjacence
        [[]]
        >>> G.ajouter_sommet()
        1
        >>> G._liste_adjacence
        [[], []]
        """
        self._liste_adjacence.append(list())
        return len(self._liste_adjacence)-1

    def aretes(self):
        """Renvoie l'ensemble des arêtes du graphe sous forme de couples (si on
        les stocke sous forme de paires, on ne peut pas stocker les boucles,
        c'est-à-dire les arêtes de la forme (u, u)).
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2)])
        >>> G.ajouter_arete(1, 1)
        >>> G.aretes()
        [(0, 1), (0, 2), (1, 1)]
        """
        aretes = []
        for u in range(self.nombre_sommets()) : 
            for v in self._liste_adjacence[u] : 
                if not (v, u) in aretes: 
                    aretes.append((u, v))
        return aretes

    def boucles(self):
        """Renvoie les boucles du graphe, c'est-à-dire les arêtes reliant un
        sommet à lui-même.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2)])
        >>> G.boucles()
        []
        >>> G.ajouter_arete(2, 2)
        >>> G.boucles()
        [(2, 2)]
        """
        boucles = []
        for u in range(self.nombre_sommets()) : 
            for v in self._liste_adjacence[u] : 
                if u == v and not (u,v) in boucles : 
                    boucles.append((u, v))
        return boucles

    def contient_arete(self, u, v):
        """Renvoie True si l'arête {u, v} existe, False sinon.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2)])
        >>> G.contient_arete(0, 2)
        True
        >>> G.contient_arete(3, 0)
        False
        """
        if not self.contient_sommet(u) or not self.contient_sommet(v) : 
            return False
        return v in self._liste_adjacence[u]

    def contient_sommet(self, u):
        """Renvoie True si le sommet u existe, False sinon.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.contient_sommet(0)
        True
        >>> G.contient_sommet(2)
        False
        """
        if len(self._liste_adjacence) <= u : 
            return False 
        return True

    def degre(self, sommet):
        """Renvoie le degré d'un sommet, c'est-à-dire le nombre de voisins
        qu'il possède. Génère une erreur si le sommet n'existe pas.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2), (1,1)])
        >>> G.degre(1)
        2
        """
        if not self.contient_sommet(sommet) : 
            raise Exception("Le sommet n'existe pas")
        
        return len(self.voisins(sommet))

    def nombre_aretes(self):
        """Renvoie le nombre d'arêtes du graphe.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2), (1, 1), (1, 2), (2, 2)])
        >>> G.nombre_aretes()
        5
        """
        return len(self.aretes())

    def nombre_boucles(self):
        """Renvoie le nombre d'arêtes de la forme {u, u}.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0, 3), (0, 0), (1, 1), (2, 2)])  
        >>> G.nombre_boucles()
        3
        """
        return len(self.boucles())

    def nombre_sommets(self):
        """Renvoie le nombre de sommets du graphe.

        >>> from random import randint
        >>> n = randint(0, 1000)
        >>> ListeAdjacence(n).nombre_sommets() == n
        True
        """
        return len(self._liste_adjacence)

    def retirer_arete(self, u, v):
        """Retire l'arête {u, v} si elle existe; provoque une erreur sinon.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0,1), (0,2)])
        >>> G.ajouter_arete(1,1)
        >>> G._liste_adjacence
        [[1, 2], [0, 1, 1], [0]]
        >>> G.retirer_arete(1, 1)
        >>> print(G._liste_adjacence)
        [[1, 2], [0], [0]]
        """
        if self.contient_arete(u, v) : 
            self._liste_adjacence[u].remove(v)
            #Double suppression si c'est une boucle
            if u == v : 
            	self._liste_adjacence[u].remove(v)
        else : 
            raise Exception("L'arete n'existe pas")

    def retirer_aretes(self, iterable):
        """Retire toutes les arêtes de l'itérable donné du graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples d'éléments (quel que soit le type du couple)."""
        for u,v in iterable : 
            self.retirer_arete(u, v)

    def retirer_sommet(self, sommet):
        """Déconnecte un sommet du graphe et le supprime.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0, 5), (0, 2), (0, 1), (1, 1), (1, 3), (1, 4), (2, 4), (3, 5)])  
        >>> G._liste_adjacence
        [[5, 2, 1], [0, 1, 1, 3, 4], [0, 4], [1, 5], [1, 2], [0, 3]]
        >>> G.retirer_sommet(1)
        >>> print(G._liste_adjacence)
        [[4, 1], [0, 3], [4], [1], [0, 2]]
        """
        if not self.contient_sommet(sommet): 
            raise Exception ("Le sommet n'existe pas")

        del self._liste_adjacence[sommet]

        for i in range(self.nombre_sommets()) : 
            while sommet in self._liste_adjacence[i]:
                self._liste_adjacence[i].remove(sommet)
            for j in range(len(self._liste_adjacence[i])) : 
                if self._liste_adjacence[i][j] > sommet : 
                    self._liste_adjacence[i][j] -= 1

    def retirer_sommets(self, iterable):
        """Efface les sommets de l'itérable donné du graphe, et retire toutes
        les arêtes incidentes à ces sommets.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_sommet()
        3
        >>> G.ajouter_sommet()
        4
        >>> G.ajouter_aretes([(0,1), (0,2), (0,3), (1,3), (1,4), (2,3), (4,4)])
        >>> G.retirer_sommets([1,2])
        >>> G._liste_adjacence
        [[1], [0], [2, 2]]
        """        

        for sommet in iterable : 
            self.retirer_sommet(sommet)

    def sommets(self):
        """Renvoie l'ensemble des sommets du graphe.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_arete(0, 3)
        >>> G.sommets()
        [0, 1, 2, 3]
        """
        res = []
        for i in range(self.nombre_sommets()) : 
            res.append(i)
        return res

    def sous_graphe_induit(self, iterable):
        """Renvoie le sous-graphe induit par l'itérable de sommets donné.
        >>> aretes = [(0,1), (3,2), (5,6), (4, 4), (1, 6), (2, 5), (0, 4), (0, 11)]
        >>> G = ListeAdjacence()
        >>> G.ajouter_aretes(aretes)
        >>> ss_graphe = G.sous_graphe_induit([0, 2, 4, 3])
        >>> print(ss_graphe._liste_adjacence)
        [[3], [2], [1], [0, 3, 3]]
        """

        graphe = ListeAdjacence()

        #On copie les aretes existantes dans le graphe de départ
        for i in range(self.nombre_sommets()) : 
            for j in range(len(self._liste_adjacence[i])) : 
                graphe.ajouter_arete(i, self._liste_adjacence[i][j])

        #On supprime les sommets qui ne sont pas dans iterable
        for i in range(len(graphe._liste_adjacence)-1, 0, -1) : 
            if i not in iterable : 
                graphe.retirer_sommet(i)

        return graphe

    def voisins(self, sommet):
        """Renvoie la liste des voisins d'un sommet.
        >>> G = ListeAdjacence()
        >>> G.ajouter_sommet()
        0
        >>> G.ajouter_sommet()
        1
        >>> G.ajouter_sommet()
        2
        >>> G.ajouter_aretes([(0, 2), (1, 2), (1, 1)])
        >>> G.voisins(1)
        [2, 1]
        """
        voisins = []

        for i in self._liste_adjacence[sommet] : 
            if not i in voisins : 
                voisins.append(i)

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

def create_dot(graphe) : 
    string = export_dot(graphe)
    fichier = open("graphe.dot", "w")
    fichier.write(string)
    fichier.close()
    os.system("dot -Tpdf graphe.dot -o graphe.pdf") #Convertit directement

def main():
    import doctest
    doctest.testmod()
    
if __name__ == "__main__":
    main()
