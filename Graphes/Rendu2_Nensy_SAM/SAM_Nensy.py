"""
Auteur : Nensy SAM
Groupe : G3
Rendu n°2
"""

class graphesOrientes(object) :	
	def __init__(self) : 
		self.dictionnaire = dict()

	def ajouter_arc(self, u, v) : 
		"""Ajoute une arête entre les sommets u et v, en créant les sommets
        manquants le cas échéant.
		>>> G = graphesOrientes()
		>>> G.ajouter_arc(2, 10)
		>>> print(G.dictionnaire)
		{2: {10}, 10: set()}
        """
        # vérification de l'existence de u et v, et création(s)
		if u not in self.dictionnaire :
			self.dictionnaire[u] = set()
		if v not in self.dictionnaire :
			self.dictionnaire[v] = set()
		self.dictionnaire[u].add(v) 

	def ajouter_arcs(self, iterable) : 
		"""Ajoute chaque couple d'arcs de iterable.
		>>> G = graphesOrientes()
		>>> G.ajouter_arcs([(2, 10), (3, 5), (4, 4)])
		>>> print(G.dictionnaire)
		{2: {10}, 10: set(), 3: {5}, 5: set(), 4: {4}}
		"""
		for u, v in iterable : 
			self.ajouter_arc(u, v)

	def ajouter_sommet(self, sommet):
		"""Ajoute un sommet (de n'importe quel type hashable) au graphe.
		>>> G = graphesOrientes()
		>>> G.ajouter_sommet(1)
		>>> G.nombre_sommets()
		1
		>>> G.sommets()
		[1]
		"""
		self.dictionnaire[sommet] = set()

	def ajouter_sommets(self, iterable) :
		"""Ajoute tous les sommets de l'itérable donné au graphe. N'importe
		quel type d'itérable est acceptable, mais il faut qu'il ne contienne
		que des éléments hashables."""
		for sommet in iterable:
			self.ajouter_sommet(sommet)

	def arcs(self) : 
		"""Retourne une liste de tuples correspondant aux arcs du graphes.
	    >>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
		>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
		>>> G.arcs()
		[(0, 1), (1, 1), (2, 0), (2, 1), (2, 4), (4, 3), (4, 5)]
		"""
		arcs = []

		for sommet in self.dictionnaire : 
			for v in self.dictionnaire[sommet] :
				arcs.append((sommet, v))
		return arcs

	def boucles(self) : 
		"""	    
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
		>>> G.ajouter_arcs([(0, 1), (2, 0), (1, 1), (2, 5), (4, 3), (2, 1), (4, 0)])
		>>> G.boucles()
		[(1, 1)]
		"""
		boucles = []
	
		for sommet in self.dictionnaire : 
			for v in self.dictionnaire[sommet] :
				if sommet == v : 
					boucles.append((sommet, v))

		return boucles

	def sommets(self) : 
		"""Renvoie le nombre de sommets du graphe.
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 10, 2, 3, 5, 100])
    	>>> G.sommets()
    	[0, 2, 3, 5, 10, 100]
    	"""
		return sorted(self.dictionnaire.keys())

	def contient_arc(self, u, v) : 
		"""
	    >>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
		>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
		>>> G.contient_arc(2, 0)
		True
		>>> G.contient_arc(5, 5)
		False
		"""
		if self.contient_sommet(u) and self.contient_sommet(v): 
			return v in self.dictionnaire[u]
		return False

	def contient_sommet(self, sommet) : 
		"""Vérifie si le graphe contient le sommet sommet.
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
		>>> G.contient_sommet(2)
		True
		>>> G.contient_sommet(10)
		False
		"""
		return sommet in self.dictionnaire

	def nombre_arcs(self):
		"""Renvoie le nombre d'arêtes du graphe.
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
    	>>> G.nombre_arcs()
    	7
    	"""
		return len(self.arcs())

	def nombre_boucles(self):
		"""Renvoie le nombre d'arêtes de la forme {u, u}.
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5), (5, 5)])
    	>>> G.nombre_boucles()
    	2
		"""
		return len(self.boucles())

	def nombre_sommets(self):
		"""Renvoie le nombre de sommets du graphe.
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 5])
    	>>> G.nombre_sommets()
    	5
    	"""
		return len(self.dictionnaire)

	def retirer_arc(self, u, v) : 
		"""
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
		>>> print(G.dictionnaire)
		{0: {1}, 1: {1}, 2: {0, 1, 4}, 3: set(), 4: {3, 5}, 5: set()}
		>>> G.retirer_arc(2, 4)
		>>> print(G.dictionnaire)
		{0: {1}, 1: {1}, 2: {0, 1}, 3: set(), 4: {3, 5}, 5: set()}
    	"""
		if self.contient_sommet(u) and self.contient_sommet(v) : 
			self.dictionnaire[u].remove(v)

	def retirer_arcs(self, iterable) : 
		"""
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
		>>> print(G.dictionnaire)
		{0: {1}, 1: {1}, 2: {0, 1, 4}, 3: set(), 4: {3, 5}, 5: set()}
		>>> G.retirer_arcs([(2, 4), (4, 3)])
		>>> print(G.dictionnaire)
		{0: {1}, 1: {1}, 2: {0, 1}, 3: set(), 4: {5}, 5: set()}
    	"""
		for u, v in iterable : 
			self.retirer_arc(u, v)

	def degre_sortant(self, sommet) : 
		"""Renvoie le nombre d'aretes sortante du sommet
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
    	>>> G.degre_sortant(0)
    	1
    	>>> G.degre_sortant(2)
    	3
    	"""
		return len(self.dictionnaire[sommet])

	def degre_entrant(self, sommet) : 
		"""
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
    	>>> G.degre_entrant(0)
    	1
    	>>> G.degre_entrant(1)
    	3
		"""
		degre = 0
		for u in self.dictionnaire : 
			if sommet in self.dictionnaire[u] : 
				degre += 1
		return degre

	def successeurs(self, sommet) : 
		"""
		>>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
    	>>> G.successeurs(2)
    	[0, 1, 4]
    	>>> G.successeurs(4)
    	[3, 5]
    	"""
		return sorted(self.dictionnaire[sommet])

	def predecesseurs(self, sommet) : 
		"""
	    >>> G = graphesOrientes()
    	>>> G.ajouter_sommets([0, 1, 2, 3, 4, 5])
    	>>> G.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 4), (4, 3), (2, 1), (4, 5)])
    	>>> G.predecesseurs(1)
    	[0, 1, 2]
    	>>> G.predecesseurs(0)
    	[2]
    	"""
		pred = []

		for u in self.dictionnaire : 
			if sommet in self.dictionnaire[u] : 
				pred.append(u)
		return sorted(pred)

def ParcoursProfondeurOrienteAux(graphe, sommet, deja_visite, parents) : 
	deja_visite[graphe.sommets().index(sommet)] = True
	for s in graphe.successeurs(sommet) : 
		if not deja_visite[graphe.sommets().index(s)] : 
			parents[graphe.sommets().index(s)] = sommet
			ParcoursProfondeurOrienteAux(graphe, s, deja_visite, parents)

def foret_profondeur(graphe) : 
	foret = type(graphe)()
	deja_visite = [False for i in range(graphe.nombre_sommets())]
	parents = [None for i in range(graphe.nombre_sommets())]
	for s in graphe.sommets() : 
		if not deja_visite[graphe.sommets().index(s)] : 
			ParcoursProfondeurOrienteAux(graphe, s, deja_visite, parents)
	for s in graphe.sommets() : 
		if parents[graphe.sommets().index(s)] != None :
			foret.ajouter_arc(parents[graphe.sommets().index(s)], s)
		if parents[graphe.sommets().index(s)] == None : 
			foret.ajouter_sommet(s)
	return foret

def largeur(graphe, s, couleur, parents) : 
	file = list()
	file.append(s)
	couleur[graphe.sommets().index(s)] = "gris"

	while len(file) > 0 : 
		premier = file[0]
		for sommet in graphe.successeurs(premier) :
			if couleur[graphe.sommets().index(sommet)] == "blanc" : 
				file.append(sommet)
				couleur[graphe.sommets().index(sommet)] = "gris"
				parents[graphe.sommets().index(sommet)] = premier
		del file[0]

def foret_largeur(graphe) : 
	foret = type(graphe)()
	couleur = ["blanc" for i in range(graphe.nombre_sommets())]
	parents = [None for i in range(graphe.nombre_sommets())]

	for s in graphe.sommets() : 
		if couleur[graphe.sommets().index(s)] == "blanc" : 
			largeur(graphe, s, couleur, parents)
	for s in graphe.sommets() : 
		if parents[graphe.sommets().index(s)] != None :
			foret.ajouter_arc(parents[graphe.sommets().index(s)], s)
		if parents[graphe.sommets().index(s)] == None : 
			foret.ajouter_sommet(s)
	return foret

def cycleOrienteAux(graphe, sommet, statuts, parents) : 
	statuts[graphe.sommets().index(sommet)] = "gris"
	for s in graphe.successeurs(sommet) : 
		if statuts[graphe.sommets().index(s)] == "gris" : 
			return (sommet, s)
		if statuts[graphe.sommets().index(s)] == "blanc" : 
			parents[graphe.sommets().index(s)] = sommet
			arc = cycleOrienteAux(graphe, s, statuts, parents)
			if arc != None : 
				return arc
	statuts[graphe.sommets().index(sommet)] = "noir"
	return None

def cycle_profondeur(graphe) : 
	statuts = ["blanc" for i in range(graphe.nombre_sommets())]
	parents = [None for i in range(graphe.nombre_sommets())]
	for s in graphe.sommets() : 
		if statuts[graphe.sommets().index(s)] == "blanc" : 
			arc = cycleOrienteAux(graphe, s, statuts, parents)
			if arc != None :
				cycle = type(graphe)()
				(x, y) = arc
				cycle.ajouter_arc(x, y)
				while x != y : 
					cycle.ajouter_arc(parents[graphe.sommets().index(x)], x)
					x = parents[graphe.sommets().index(x)]
				return cycle
	return None	

def export_dot(graphe):
    """Renvoie une chaîne encodant le graphe au format dot."""
    string = "digraph graphe { "

    sommets = "\n"
    for sommet in graphe.sommets() : 
        sommets += "\t" + str(sommet) + ";\n"

    arcs = "" 
    for u, v in graphe.arcs() : 
        arcs += "\t" + str(u) + " -> " + str(v) + ";\n"

    return string + sommets + arcs + "}"

def creer_dot(graphe, fichier): 
	string = export_dot(graphe)
	fichier = open(fichier, "w")
	fichier.write(string)
	fichier.close()

def main():
    import doctest
    doctest.testmod()
    
    """GAlpha = graphesOrientes()
    GAlpha.ajouter_sommets(['a', 'b', 'c', 'd', 'e', 'f'])
    GAlpha.ajouter_arcs([('a', 'c'), ('b', 'a'), ('c', 'c'), ('c', 'f'), ('e','f'), ('c', 'b'), ('e', 'a')])
    creer_dot(GAlpha, "oriente.dot")
    creer_dot(foret_profondeur(GAlpha), "foretProfondeur.dot")
    creer_dot(foret_largeur(GAlpha), "foretLargeur.dot")
    creer_dot(cycle_profondeur(GAlpha), "cycleProfondeur.dot")

    G2 = graphesOrientes()
    G2.ajouter_sommets([0, 2, 4, 3, 10])
    G2.ajouter_arcs([(0, 2), (2, 0), (3, 10), (4, 2), (4, 3), (10, 2)])
    creer_dot(G2, "orienteNum.dot")
    creer_dot(foret_profondeur(G2), "foretProfondeur2.dot")
    creer_dot(foret_largeur(G2), "foretLargeur2.dot")
    creer_dot(cycle_profondeur(G2), "cycleProfondeur2.dot")"""

    G3 = graphesOrientes()
    G3.ajouter_sommets([0, 1, 2, 3, 4, 5])
    G3.ajouter_arcs([(0, 1), (1, 1), (2, 0), (2, 5), (3, 4), (2, 1), (4, 0)])
    creer_dot(G3, "oriente3.dot")
    creer_dot(foret_profondeur(G3), "foretProfondeur3.dot")
    creer_dot(foret_largeur(G3), "foretLargeur3.dot")
    creer_dot(cycle_profondeur(G3), "cycleProfondeur3.dot")
	

if __name__ == "__main__":
    main()

