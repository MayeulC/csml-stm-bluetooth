# CSML, partie STM32

## LICENCE
Le code de ce dépôt est licencié sous la licence GPLv3 à l'exception des
fichiers sous copyright STMicroelectronics. Voir le fichier LICENSE pour le
texte complet de la GPLv3.

## Compilation
Le code est conçu pour être compilé depuis le dossier [toolchain](toolchain).

La commande `make` peut être utilisée pour compiler le projet. `make flash` est
utilisé pour envoyer le projet sous la carte nucleo.

### Dépendances
Sont nécessaires pour la compilation les paquets suivants:
```
make
binutils
arm-none-eabi-gcc
arm-none-eabi-binutils
arm-none-eabi-gdb (uniquement pour le débogage)
openocd (uniquement pour la programmation de la carte)
```

## Utilisation
La carte STM reçoit un signal PWM sur son entrée A0. Lorsque le rapport
cyclique de celui-ci devient inférieur à 50%, un signal est envoyé sur son
UART. Ce signal est destiné à un module série Bluetooth, et est constitué
ainsi: `Ax\r\n`, où `x` est un octet compris entre 0 et 255, indiquant le
rapport cyclique moyen actuel.

La carte peut aussi recevoir par Bluetooth un octet `R`, lui demandant le
rapport cyclique moyen actuel. Celle-ci répond ensuite par `Rx\r\n`, avec x la
valeur de ce dernier.

Le module Bluetooth fonctionne à 115200 bauds, et est connecté sur les ports
A2 (Port TX de l'UART2 du STM) et A3 (Port RX de l'UART2 du STM).

## Documentation

### CubeMX
Un rapport de synthèse et d'autres documents sont présents dans le répertoire
CubeMX/

### Architecture
Le système doit calculer le rapport cyclique d'un signal PWM arrivant sur une
de ses entrées.
Afin de faire cela, le Timer 5 est mis en mode de déclenchement sur
interruption externe, sur les deux fronts. La routine présente dans
[interruption_timer.c](Src/interruption_timer.c) est appelée à chaque
changement d'état, et calcule le rapport cyclique actuel.

Une fois le rapport cyclique calculé, celui-ci est stocké dans la variable
globale `volatile uint8_t duty_cycle`, et le drapeau
`volatile bool interrupt_received` est levé.

La boucle principale du programme (ligne 116 de [main.c](Src/main.c#L116)) vérifie
ce drapeau, et fournit le rapport cyclique à la fonction
`register_current_duty_cycle` de [sendalarm.c](Src/sendalarm.c).
Cette fonction ajoute cette valeur à un buffer circulaire, et calcule la valeur
moyenne lorsque celui-ci est rempli.
La boucle principale du programme vérifie ensuite que cette valeur ne déclenche
pas d'alarme grâce à la fonction `is_alarm_triggered`.
Si une alarme est déclenchée, celle-ci est envoyée sur la liaison série
Bluetooth comme précédemment documenté.

La boucle principale vérifie ensuite si une instruction de lecture du rapport
cyclique a été reçue, et y réagit.
