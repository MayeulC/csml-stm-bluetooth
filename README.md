# CSML, partie STM32

## LICENCE
Le code de ce dépot est licencié sous la licence GPLv3 à l'exception des fichiers
sous copyright STMicroelectronics. Voir le fichier LICENSE pour le texte complet
de la GPLv3.

## Compilation
Le code est conçu pour être compilé depuis le dossier "Toolchain".

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
UART. Ce signal est destiné à un module série bluetooth, et est constitué
ainsi: `Ax\r\n`, où `x` est un octet compris entre 0 et 255, indiquant le
rapport cyclique moyen actuel.

La carte peut aussi recevoir par bluetooth  un octet `R`, lui demandant le
rapport cyclique moyen actuel. Celle-ci répond ensuite par `Rx\r\n`, avec x la
valeur de ce dernier.

TODO: documenter les PINs UART 1 et 2

