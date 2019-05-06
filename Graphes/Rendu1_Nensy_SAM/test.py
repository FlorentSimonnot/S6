from ListeAdjacence import *
import random

def main():
	n = random.randint(0, 200)
	
	graphe = ListeAdjacence()

	for i in range(n) : 
		graphe.ajouter_sommet()

	for i in range(n) : 
		u = random.randint(0, n-1)
		v = random.randint(0, n-1)
		graphe.ajouter_arete(u, v)

	create_dot(graphe)


if __name__ == "__main__":
    main()
