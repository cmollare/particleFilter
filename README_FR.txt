

-----------------INSTALLATION------------------------

Pour installer cette library, vous avez besoin de :
	- cmake
	- boost version 1.48 (et boost random)
	- opencv 2.4.5 (à compiler soit même, n'existant pas encore en package)
	
Se mettre dans le dossier du projet
créer un répertoire "build"
exécuter les commandes suivantes :
	cd build
	cmake ..
	make
	
exécuter le fichier : ../bin/demo


---------------------USAGE--------------------------
Cette library implémente les filtres particulaire suivant :
	-SIR, inspiré du papier : conditionnal density propagation for visual tracking
	-ICOND, inspiré du papier : unifying low-level and high-level tracking in a stochastic framework

toutes les classes précédées par demo sont à réimplémenter ou dériver suivant votre usage, et permette d'avoir un exemple de fonctionnement.
Elles ont été crées pour suivre une couleur dans l'image (réglable durant le filtrage grâce à l'interface de controle).
Le Mouse detector fonctionne comme un détecteur de la position de la souris lorsque la touche ctrl est enfoncée.

Pour toute question, me contacter à christophe.mollaret@gmail.com
