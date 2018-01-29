# Design3

Le git contient les dossiers suivants :

* Base\_Station\_QT\_Workspace :
    Le code source de la station de base développé avec [Qt](www.qt.io) que vous pouvez downloader [ici](www.qt.io/download). Selectionnez la version open-source.

* Motor\_Controller\_SW4STM\_Workspace :
    Le code source du controlleur de moteur réalisé avec le board STM32F407 Discovery. Le IDE utilisé est System Workbench 4 STM32 (SW4STM32) 


*Petit rappel (sous linux)*
* Creer un dossier 'Design_3_git' dans Documents.
* Downloader git : `sudo apt-get install git-all`
* Downloader xclip pour mettre des chose dans le clipboard : `sudo apt-get install xclip`
* Vérifier si vous avez une clé SSH générée : `ls -al ~/.ssh` 
* Sinon générer votre clé SSH : `ssh-keygen -t rsa -b 4096 -C "votre.adresse.email@email.com"`
* Copiez votre clé SSH dans le clipboard : `xclip -sel clip < ~/.ssh/id_rsa.pub`
* Connectez-vous sur github, puis en haut à droite cliquez sur votre photo de profil, puis allez dans settings
* Cliquez sur SSH and GPG keys
* Cliquez sur New SSH Key
* Collez votre clé SSH.
* Indiquez à git votre adresse email : `git config --global user.email "votre.adresse.email@email.com"`
* Indiquez à git votre nom : ` git config --global user.name "Votre Nom"`

* Dans le dossier 'Design_3_git' ouvrez un terminal.
* Clonez le repository : `git clone git@github.com:simonbeaudoin0935/Design3.git`

*N'oubliez pas*
* Quand vous modifiez la structure, ajoutez ou supprimez des fichiers : `git add .`
* Quand vous voulez commit les changements : `git commit -m "votre commentaire"`
* Enfin : `git push`

*Remarques pour Mac OS X:
* apt-get est utilisé pour installer des packages avec Linux. L'équivalent pour Mac est Homebrew.
* Si `xclip -sel clip < ~/.ssh/id_rsa.pub` ne copie pas la clé, essayez d'obtenir la clé publique avec cat `~/.ssh/id_rsa.pub puis copiez là.`
