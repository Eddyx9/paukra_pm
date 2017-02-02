#! /bin/bash
#install.paukra.com

learn_more=git.paukra.com/open-source/btsoot
repo=https://git.paukra.com/open-source/btsoot.git
folder=btsoot
rename_from=btsoot.py
rename_to=btsoot

###############################################################################

update_system() {
    echo "update system"
    sudo apt-get update
    sudo apt-get upgrade
}

update_programm() {
    uninstall()
    install()
}

install() {
    cd /etc
    git clone $repo
    cd /etc/$folder
    mv $rename_from $rename_to
    cp /etc/$folder/$rename_to /usr/local/bin
}

uninstall() {
    rm /etc/$folder
    rm /usr/local/bin/$rename_to
}


main() {
    sudo su
    echo "\n"
    firefox $learn_more
    