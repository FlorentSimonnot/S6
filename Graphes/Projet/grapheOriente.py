class grapheOriente(object) :	
	def __init__(self) : 
		self.dictionnaire = dict()

	def ajouter_arc(self, u, v) : 
		if u not in self.dictionnaire :
			self.dictionnaire[u] = set()
		if v not in self.dictionnaire :
			self.dictionnaire[v] = set()
		self.dictionnaire[u].add(v) 

	def ajouter_arcs(self, iterable) : 
		for u, v in iterable : 
			self.ajouter_arc(u, v)

	def ajouter_sommet(self, sommet):
		self.dictionnaire[sommet] = set()

	def ajouter_sommets(self, iterable) :
		for sommet in iterable:
			self.ajouter_sommet(sommet)

	def arcs(self) : 
		arcs = []

		for sommet in self.dictionnaire : 
			for v in self.dictionnaire[sommet] :
				arcs.append((sommet, v))
		return arcs

	def boucles(self) : 
		boucles = []
	
		for sommet in self.dictionnaire : 
			for v in self.dictionnaire[sommet] :
				if sommet == v : 
					boucles.append((sommet, v))

		return boucles

	def sommets(self) : 
		return sorted(self.dictionnaire.keys())

	def contient_arc(self, u, v) : 
		if self.contient_sommet(u) and self.contient_sommet(v): 
			return v in self.dictionnaire[u]
		return False

	def contient_sommet(self, sommet) : 
		return sommet in self.dictionnaire

	def nombre_arcs(self):
		return len(self.arcs())

	def nombre_boucles(self):
		return len(self.boucles())

	def nombre_sommets(self):
		return len(self.dictionnaire)

	def retirer_arc(self, u, v) : 
		if self.contient_sommet(u) and self.contient_sommet(v) : 
			self.dictionnaire[u].remove(v)

	def retirer_arcs(self, iterable) : 
		for u, v in iterable : 
			self.retirer_arc(u, v)

	def degre_sortant(self, sommet) : 
		return len(self.dictionnaire[sommet])

	def degre_entrant(self, sommet) : 
		degre = 0
		for u in self.dictionnaire : 
			if sommet in self.dictionnaire[u] : 
				degre += 1
		return degre

	def successeurs(self, sommet) : 
		return sorted(self.dictionnaire[sommet])

	def predecesseurs(self, sommet) : 
		pred = []

		for u in self.dictionnaire : 
			if sommet in self.dictionnaire[u] : 
				pred.append(u)
		return sorted(pred)