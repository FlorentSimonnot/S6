
from graphe import *
from grapheOriente import *
from random import *
import math 

def numerotation(G) : 

	debut = dict()
	parent = dict()
	ancetre = dict()

	for i in sorted(G.sommets()) : 
		debut[i] = 0
		parent[i] = None
		ancetre[i] = math.inf

	instant = 0

	def numerotationAux(s) : 
		nonlocal instant
		instant += 1
		debut[s] = ancetre[s] = instant

		for t in G.voisins(s) : 
			if debut[t] > 0 :
				if parent[s] != t : 
					ancetre[s] = min(ancetre[s], debut[t])
			else : 
				parent[t] = s
				numerotationAux(t)
				ancetre[s] = min(ancetre[s], ancetre[t])

	for i in G.sommets() : 
		if debut[i] == 0 : 
			numerotationAux(i)

	return debut, parent, ancetre

def degre_sortant(iterable, sommet) : 
	res = 0
	for v in iterable : 
		if iterable[v] == sommet : 
			res += 1
	return res

def descendant(iterable, sommet) : 
	res = []

	for v in iterable : 
		if iterable[v] == sommet : 
			res.append(v)
	return res

def points_articulation(G) : 
	debut, parent, ancetre = numerotation(G)
	articulation = []

	racines = []
	for v in G.sommets() : 
		if parent[v] == None : 
			racines.append(v)

	for dep in racines : 
		if degre_sortant(parent, dep) >= 2 : 
			articulation.append(dep)

	racines.append(None)

	for v in G.sommets() : 
		if not parent[v] in racines and ancetre[v] >= debut[parent[v]] : 
			if not parent[v] in articulation : 
				articulation.append(parent[v])


	return sorted(articulation)

def ponts(G) : 
	debut, parent, ancetre = numerotation(G)
	ponts = []

	for v in parent : 
		if parent[v] != None : 
			if ancetre[v] > debut[parent[v]] : 
				ponts.append((parent[v], v))

	return ponts

def creer_arcs_retours(G, iterable) : 
	aretes_parents = []
	res = []

	aretes = G.aretes()
	for u in iterable : 
		if iterable[u] != None : 
			aretes_parents.append((iterable[u], u, None))

	for a in aretes : 
		if not a in aretes_parents : 
			res.append(a)

	return res

def trouver_ancetre(G, ancetre) : 

	sommets = G.sommets()
	return sommets[ancetre]

def amelioration_points_articulation(G) : 
	res = []

	copie = G
	debut, parent, ancetre = numerotation(copie)
	points = sorted(points_articulation(copie), reverse=True)
	sommets = G.sommets()

	
	racines = []
	for v in G.sommets() : 
		if parent[v] == None : 
			racines.append(v)	

	while 1: 
		if len(points) == 0 : 
			break 
		if not points[0] in racines : 
			for v in descendant(parent, points[0]) :
				if not (v, trouver_ancetre(G, ancetre[points[0]])) in creer_arcs_retours(G, parent) :
					for ra in racines : 
						res.append((ra, v))
						copie.ajouter_arete(ra, v, None)
		else : 
			fils_de_racine = descendant(parent, points[0])
			i = 0
			while i < len(fils_de_racine) - 1 :
				copie.ajouter_arete(fils_de_racine[i], fils_de_racine[i+1], None)
				res.append((fils_de_racine[i], fils_de_racine[i+1]))
				i += 1


		points = sorted(points_articulation(copie), reverse=True)

	return res

def foret(G) : 
	debut, parent, ancetre = numerotation(G)
	creer_arcs_retours(G, parent)

def extremite_ponts(G, sommet) : 

	for u, v in ponts(G) : 
		if u == sommet or v == sommet : 
			return True
	return False

def deuxieme_extremite(G, sommet) : 
    for u, v in ponts(G) : 
        if u == sommet : 
            return v 
        if v == sommet : 
            return u
    return None

def est_deuxieme_extremite(G, sommet, sommet2) :
	for u, v in ponts(G) : 
		if u == sommet and v == sommet2 or v == sommet and u == sommet2 : 
			return True
	return False

def sommet_dans_composante(G, sommet, composante) : 
    sommet2 = deuxieme_extremite(G, sommet)
    if sommet2 != None : 
        if sommet2 in composante : 
            return True
    return False

def chercher_composantes(G, depart, composante, extremite_deux, deja_visites=None):
    resultat = list()

    if deja_visites == None:
        deja_visites = dict()
        for s in G.sommets():
            deja_visites[s] = False

    a_traiter = []
    a_traiter.append(depart)

    if not depart in composante :
    	composante.append(depart)

    while len(a_traiter) > 0:
        dernier = len(a_traiter) - 1
        sommet = a_traiter[dernier]
        a_traiter.pop()

        if deja_visites[sommet] == False:

            if sommet != extremite_deux and not est_deuxieme_extremite(G, depart, sommet):
                resultat.append(sommet)
                deja_visites[sommet] = True
                for v in sorted(G.voisins(sommet)):
                    if extremite_ponts(G, v):
                        if not sommet_dans_composante(G, v, composante) and not v in composante and not est_deuxieme_extremite(G, sommet, v):
                            composante.append(v)
                            if deja_visites[v] == False:
                                a_traiter.append(v)
                    else : 
                        if not v in composante : 
                        	composante.append(v)
                        if deja_visites[v] == False:
                            a_traiter.append(v)

    return resultat

def composantes(G):
    composantes = dict()
    res = []

    for (u, v) in ponts(G):
        composantes[u] = list()
        composantes[v] = list()
        chercher_composantes(G, u, composantes[u], v)
        chercher_composantes(G, v, composantes[v], u)

    #On enlève les doublons
    for u in composantes:
        if composantes[u] not in res:
            res.append(composantes[u])
                    
    return res

def est_feuille(G, composante):
    res = 0

    for s in composante:
        if extremite_ponts(G, s):
            res += 1
    return res == 1

def feuilles(G):
    res = list()

    for c in composantes(G):
        if est_feuille(G, c):
            res.append(c)
    
    return res

def relier_feuilles(G, f1, f2):
    x = randint(0, len(f1) - 1)
    y = randint(0, len(f2) - 1)

    return (f1[x], f2[y])

def parcours_largeur_iteratif(G, depart, deja_visites=None):
    resultat = list()

    if deja_visites == None:
        deja_visites = dict()
        for s in G.sommets():
            deja_visites[s] = False

    a_traiter = []
    a_traiter.append(depart)

    while a_traiter != []:
        dernier = len(a_traiter) - 1
        sommet = a_traiter[dernier]
        a_traiter.pop()

        if deja_visites[sommet] == False:

            resultat.append(sommet)
            deja_visites[sommet] = True
            for v in sorted(G.voisins(sommet)):
                if deja_visites[v] == False:
                    a_traiter.append(v)

    return resultat

def est_connexe(G):
	if G.nombre_sommets() == 0:
		return True

	depart = G.sommets()[0]
	return len(parcours_largeur_iteratif(G, depart)) == G.nombre_sommets() 

def amelioration_ponts(G):
	collection = feuilles(G)
	res = []
	print("feuilles", collection)
	print("composantes", composantes(G))
	if est_connexe(G): 
		i = 0
		while i < len(collection) :
			if i == len(collection) - 1 : 
				j = 0
			else : 
				j = i+1
			x = collection[i]
			y = collection[j]
			res.append(relier_feuilles(G, x, y))
			i+=1

	return res

def main() : 
	G = Graphe()
	G.ajouter_sommets(zip('abcdefghijklmn', [None] * 14))
	G.ajouter_aretes(
     [('a', 'b', None), ('b', 'c', None), ('c', 'd', None), ('d', 'a', None), ('c', 'e', None),
     ('e', 'f', None), ('f', 'g', None), ('g', 'i', None), ('g', 'm', None),
     ('i', 'j', None), ('i', 'k', None), ('k', 'l', None), ('l', 'm', None), ('m', 'n', None),
     ('n', 'l', None)])
	for u, v in amelioration_ponts(G) : 
		G.ajouter_arete(u, v, None)
	creer_dot(G, "res.dot")
	print(ponts(G))

if __name__ == "__main__":
    main()