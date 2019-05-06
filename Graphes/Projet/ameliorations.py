from graphe import *
from fragilite import *
import argparse
import operator

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

	args = parser.parse_args()
	G = Graphe()

	print(args)

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

	if args.ameliorer-points : 
		apoints = amelioration_points_articulation(G)

	if args.ameliorer-ponts : 
		ap = ameliorer_ponts(G)




if __name__ == "__main__":
    main()

