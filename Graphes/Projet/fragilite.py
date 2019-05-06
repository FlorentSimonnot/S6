
from graphe import *
from grapheOriente import *
import math 

def numerotation(G) : 

	debut = dict()
	parent = dict()
	ancetre = dict()

	for i in G.sommets() : 
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

