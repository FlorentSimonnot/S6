
class Graphe(object) : 

	def __init__(self) : 
		self.dictionnaire = dict()
		self.tableau = list()

	def nom_sommet(self, sommet) : 
		for s, nom in self.tableau : 
			if s == sommet : 
				return nom

	def ajouter_arete(self, u, v, nom_ligne) : 
		if not u in self.dictionnaire:
			self.dictionnaire[u] = list()
		if not v in self.dictionnaire:
			self.dictionnaire[v] = list()
		self.dictionnaire[u].append((v, nom_ligne))
		self.dictionnaire[v].append((u, nom_ligne))

	def ajouter_aretes(self, iterable) : 
		for u, v, nom_ligne in iterable : 
			self.ajouter_arete(u, v, nom_ligne)

	def ajouter_sommet(self, sommet, identifiant):
		self.dictionnaire[sommet] = list()
		self.tableau.append([sommet, identifiant])

	def ajouter_sommets(self, iterable):
		for sommet, identifiant in iterable:
			self.ajouter_sommet(sommet, identifiant)

	def aretes(self):
		res = []

		for u in sorted(self.dictionnaire.keys()) : 
			for (v, nom_ligne) in sorted(self.dictionnaire[u]) : 
				if not (v, u, nom_ligne) in res: 
					res.append((u,v,nom_ligne))
		return res

	def sommets(self) : 
		res = []
		for s in self.dictionnaire.keys() :
			res.append(s)
		return sorted(res)

	def rechercher_sommet(self, s) : 
		for sommet, identifiant in self.tableau : 
			if sommet == s : 
				return identifiant
		return None

	def rechercher_id_station(self, nom) : 
		for sommet, identifiant in self.tableau : 
			if identifiant == nom : 
				return sommet
		return -1

	def sommets_et_identifiants(self, option) :
		return sorted(self.tableau, key=option)

	def nombre_sommets(self) : 
		return len(self.dictionnaire)

	def voisins(self, sommet) : 
		res = [] 
		for s, identifiant in self.dictionnaire[sommet] : 
			res.append(s)
		return sorted(res)

	def degre(self, sommet) : 
		return len(self.voisins(sommet))

	def debug(self) : 
		fichier = open("debug.txt", "w")

		for s in self.dictionnaire.keys() : 
			fichier.write(self.rechercher_sommet(s)+"\n")
			for connexion in self.dictionnaire[s] : 
				fichier.write("\t"+str(self.rechercher_sommet(connexion[0]))+"\n")
			fichier.write("\n")

		fichier.close()



def charger_donnees(graphe, nom_fichier) : 
	flag_station = False 
	flag_connexions = False
	fichier = open(nom_fichier, "r")

	ligne = nom_fichier.split('/')

	for line in fichier.readlines() : 
		if line == "# stations\n" : 
			flag_station = True 
		if line == "# connexions\n" : 
			flag_station = False
			flag_connexions = True
			
		if flag_station == True and line != "# stations\n": 
			graphe.ajouter_sommet(int(line.split(':')[0]), (line.split(':')[1]).strip('\n'))
		if flag_connexions == True and line != "# connexions\n": 
			graphe.ajouter_arete(int(line.split('/')[0]), int(line.split('/')[1]), (ligne[len(ligne)-1]).strip('.txt'))

	fichier.close()

def export_dot(graphe):
    """Renvoie une chaîne encodant le graphe au format dot."""
    string = "graph graphe { "

    sommets = "\n"
    for sommet in graphe.sommets() : 
        sommets += "\t" + str(sommet) + ";\n"

    aretes = "" 
    for u, v, nom in graphe.aretes() : 
    	if nom != None :
        	aretes += "\t" + str(u) + " -- " + str(v) + " [" + "label=" + nom + "] " + ";\n"
    	else : 
    		aretes += "\t" + str(u) + " -- " + str(v) + " [" + "label=None" + "] " + ";\n"

    return string + sommets + aretes + "}"

def creer_dot(graphe, fichier): 
	string = export_dot(graphe)
	fichier = open(fichier, "w")
	fichier.write(string)
	fichier.close()