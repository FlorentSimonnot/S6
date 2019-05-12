from graphe import *
from fragilite import *
import argparse
import operator
import os

METROS = ["1", "2", "3", "3b", "4", "5", "6", "7", "7b", "8", "9", "10", "11", "12", "13", "14"]
RER = ["A", "B"]

def main() : 
	parser = argparse.ArgumentParser()
	parser.add_argument("--metro", type=str, nargs="*", help="the base")
	parser.add_argument("--rer", type=str, nargs="*", help="the exponent")
	parser.add_argument("--liste-stations", action="store_true",  help="affiche la liste des stations")
	parser.add_argument("--articulations", action="store_true", help="affiche les points d'articulations")
	parser.add_argument("--ponts", action="store_true", help="affiche les ponts")
	parser.add_argument("--ameliorer-ponts", action="store_true", help="améliore les ponts")
	parser.add_argument("--ameliorer-points", action="store_true", help="améliore les points d'articulation")
	parser.add_argument("--visualise", action="store_true", help="permet de visualiser le graphe de base")
	args = parser.parse_args()

	G = Graphe()

	if args.metro != None: 
		if len(args.metro) == 0: 
			metros = METROS
		else :
			metros = args.metro
		for metro in metros : 
			charger_donnees(G, "données/METRO_"+str(metro)+".txt")
			print("Chargement de la ligne "+str(metro)+" réussi")
		print("Le réseau contient "+str(len(G.sommets()))+" sommets et "+str(len(G.aretes()))+" aretes\n")
	elif args.rer != None or len(args.rer) == 0 : 
		if len(args.rer) == 0: 
			rers = RER
		else :
			rers = args.rer
		for rer in rers : 
			charger_donnees(G, "données/RER_"+str(rer)+".txt")
			print("Chargement de la ligne "+str(rer)+" réussi")
		print("Le réseau contient "+str(len(G.sommets()))+" sommets et "+str(len(G.aretes()))+" aretes\n")

	if args.visualise : 
		creer_dot(G, "visualise.dot")
		os.system("dot -Tpdf visualise.dot -o visualise.pdf") #Convertit directement

	if args.liste_stations : 
		for station, identifiant in G.sommets_et_identifiants(operator.itemgetter(1)) : 
			print(identifiant+" ("+str(station)+")")
		print("\n")

	if args.ponts : 
		pont = ponts(G)
		print("Le réseau contient les "+str(len(pont))+" ponts suivants :")
		for s1, s2 in pont : 
			print(G.rechercher_sommet(s1) + " -- "+ G.rechercher_sommet(s2))
		print("\n")

	if args.articulations : 
		arti = points_articulation(G)
		print("Le réseau contient les "+str(len(arti))+" points d'articulations suivants :")
		for sommet in arti : 
			print(G.rechercher_sommet(sommet))
		print("\n")

	if args.ameliorer_points : 
		print("Il y a", len(points_articulation(G)), "points d'articulations")
		for u, v in amelioration_points_articulation(G):
			G.ajouter_arete(u, v, None)
		print("Après amélioration il y a", len(ponts(G)), "point(s) d'articulation")

	if args.ameliorer_ponts : 
		creer_dot(G, "resultat.dot")
		print("Il y a", len(ponts(G)), "ponts")
		for u, v in amelioration_ponts(G):
			G.ajouter_arete(u, v, None)
		print("Après amélioration il y a", len(ponts(G)), "pont(s)")


if __name__ == "__main__":
    main()
