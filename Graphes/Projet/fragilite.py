from graphe import *
from random import *
from operator import itemgetter
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
			if debut[t] :
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

def getKey(item):
    return item[0]

def ponts(G) : 
	debut, parent, ancetre = numerotation(G)
	ponts = []
	for v in parent : 
		if parent[v] != None: 
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

def extremite_ponts(G, sommet) : 

	for u, v in ponts(G) : 
		if u == sommet or v == sommet : 
			return True
	return False

def est_deuxieme_extremite(G, sommet, sommet2) :
	for u, v in ponts(G) : 
		if u == sommet and v == sommet2 or v == sommet and u == sommet2 : 
			return True
	return False

def sommet_dans_composante(G, sommet, composante) : 
	for s in deuxieme_extremite(G, sommet) : 
		if s in composante : 
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

			if sommet != extremite_deux :
				resultat.append(sommet)
				deja_visites[sommet] = True
    
				for v in sorted(G.voisins(sommet)):
					if extremite_ponts(G, v):
						if not sommet_dans_composante(G, v, composante) :
							composante.append(v)
							if not deja_visites[v]:
								a_traiter.append(v)
					else : 
						composante.append(v)
						if not deja_visites[v] : 
							a_traiter.append(v)

	return resultat

def composantes(G) : 
	composantes = dict()
	res = []

	for (u, v) in ponts(G) : 
		composantes[u] = list() 
		composantes[v] = list()
		chercher_composantes(G, u, composantes[u], v)
		chercher_composantes(G, v, composantes[v], u)

	for u in composantes : 
		if composantes[u] not in res : 
			res.append(composantes[u])

	return res

def est_feuille(G, composante):
    res = 0

    for s in composante:
        if extremite_ponts(G, s):
            res += 1
    return res == 1


def csp(G) : 
	res = set()
	deja_visite = dict()

	def csp_aux(depart, extremite):

		deja_visite[depart] = True
		save.add(depart)

		for voisin in sorted(G.voisins(depart)) :
			if not deja_visite[voisin] and voisin != extremite : 
				if not extremite_ponts(G, voisin) : 
					csp_aux(voisin, extremite)
				else : 
					save.add(voisin)

	for u, v in sorted(ponts(G)) : 
		for i in range(2) :
			save = set()
			for s in G.sommets() : 
				deja_visite[s] = False
			csp_aux(u, v)
			res.add(tuple(save))
   
			tmp = u 
			u = v
			v = tmp

	return res

def feuilles(G):
    res = list()
	
    for c in csp(G):
        if est_feuille(G, c):
            res.append(c)
    
    return res

def sont_dans_meme_composantes(a, b, composantes_connexes) : 
	index_a = 0
	index_b = 0
	for i in range(len(composantes_connexes)) : 
		if a in composantes_connexes[i] : 
			index_a = i
		if b in composantes_connexes[i] : 
			index_b = i
	return index_a == index_b

def aretes_existante(G, s1, s2) : 
	for u, v, ligne in G.aretes() :
		if u == s1 and v == s2 : 
			return True 
	return False

def relier_feuilles(G, f1, f2, composantes_connexes):
	x = randint(0, len(f1) - 1)
	y = randint(0, len(f2) - 1)
	if composantes_connexes == None : 
		return (f1[x], f2[y])
	else : 
		if sont_dans_meme_composantes(x, y, composantes_connexes) : 
			return (f1[x], f2[y])

def parcours_largeur_iteratif(G, depart, deja_visites=None):
	resultat = list()

	if deja_visites == None:
		deja_visites = dict()
		for s in G.sommets():
			deja_visites[s] = False

	a_traiter = []
	a_traiter.append(depart)

	while len(a_traiter) > 0:
		sommet = a_traiter[0]
		del a_traiter[0]

		if not deja_visites[sommet]:
			resultat.append(sommet)
			deja_visites[sommet] = True
			for v in sorted(G.voisins(sommet)):
				if not deja_visites[v]:
					a_traiter.append(v)

	return resultat

def est_connexe(G):
	if G.nombre_sommets() == 0:
		return True

	depart = G.sommets()[0]
	return len(parcours_largeur_iteratif(G, depart)) == G.nombre_sommets() 

def composantes_connexes(G) : 

	res = []
	deja_visites = dict()
	for s in G.sommets():
		deja_visites[s] = False
	for s in G.sommets() : 
		if not deja_visites[s] : 
			res.append(parcours_largeur_iteratif(G, s, deja_visites))
	return res
					

def amelioration_ponts(G) : 
	f = feuilles(G)
	res = list()
 
	if est_connexe(G) : 
		cc = None
	else : 
		cc = composantes_connexes(G)
  
	for i in range(len(f) - 1) : 
		lien = relier_feuilles(G, f[i], f[i+1], cc)
		if not lien == None : 
			res.append((lien[0], lien[1]))

        
	return res
