#CHAMBELLON_Lab1
# CHAMBELLON_Lab2

La structure finale du système est représentée dans le schéma ci-dessous :

![image](https://github.com/ESN2024/CHAMBELLON_Lab2/assets/156073044/2e4748b2-1a8b-4c25-b6c1-977bf86154b6)
 
On utilise une seule PIO de 12 bits au lieu de trois de 4 bits. 
Le NIOS2 génère trois signaux de 4 bits pour les unités, dizaines et centaines, dirigés vers le composant bin_to_7seg. 
Un timer cadence l'incrémentation du compteur à chaque seconde.
Les LEDs de l'afficheur 7 segments ont été configuré en suivant le User Manual de la carte, pour savoir quel pin correspond à quel segment.

Pour le programme main.c, voici comment le compteur fonctionne du point de vue logiciel :

Lorsque les 4 premiers bits atteignent 1010 (10 en décimal), j'ajoute 6 pour incrémenter les dizaines (ex : 9 à 10).
Quand le compteur atteint 0000 1010 0000 (160 en décimal), j'ajoute 96 pour incrémenter les centaines (ex : 99 à 100).

Ce processus est implémenté dans la routine d'interruption timer_irq, qui se déclenche toutes les secondes.

Voici la démonstration du fonctionnement du compteur dans la vidéo ci-dessous:

https://github.com/ESN2024/CHAMBELLON_Lab2/assets/156073044/53c1d5a5-a11e-4c13-abd0-dbd37e840a4e

Ce Lab 2 nous a permis de découvrir comment implémenter un timer et configurer les afficheurs 7 segments de la carte.
