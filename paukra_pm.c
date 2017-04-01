/* paukra_pm.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

#define EXEC  X_OK

char command[256];

const char name[] = "btsoot";
const char folder[] = "btsoot";
const char repo[] = "https://github.com/paulkramme/btsoot";
const char learn_more[] = "git.paukra.com/open-source/btsoot";
const char message[] = "Text Text Text Text Text Text Text Text Text Text Text";

int getch(void) {
   /* enable getch()
    * this funktion is from github.com/paulkramme/getch-lib/blob/master/getch.c
    */
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( 0u | ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/*
void language_c() {
    // install if program is in c (needs makefile)
    system("apt-get install build-essential");
    
    snprintf(command, 255, "make %s", name);
    system(command);
    memset(command, 0, 255);
    
    snprintf(command, 255, "cp %s /usr/local/bin", name);
    system(command);
    memset(command, 0, 255);
    
    printf("language == c");
}

language_py() {
    // install if program is in python
    
    snprintf(command, 255, "mv $name.py %s", name);
    system(command);
    memset(command, 0, 255);
    
    snprintf(command, 255, "cp %s /usr/local/bin", name);
    system(command);
    memset(command, 0, 255);
    
    printf("language == py");
}

test_language() {
    # identify right language
    if (access(name.c, F_OK)
    cd /etc/$folder
    
    if [ -e $name.c ]
        then
            language_c
        elif [ -x $name ] || [ -x $name.py ]
            then
                language_py
        else
            echo "ERROR: no valid language or no main program" >> $log
    fi
}
*/

int update_system() {
    // update system
    system("sudo apt-get update");
    system("sudo apt-get upgrade");
    printf("updated system\n");
    return 0;
}

int install_folder() {
    // install folder for installing or updating
    update_system();
    system("cd /etc");
    
    snprintf(command, 256, "git clone %s", repo);
    system(command);
    memset(command, 0, 256);
    return 0;
}

int uninstall_folder() {
    // uninstall folder after installing or updating / remove when uninstall progam
    snprintf(command, 256, "sudo rm -r /etc/%s", folder);
    system(command);
    memset(command, 0, 256);
    return 0;
}

int install_exec() {
    // install executable (c/py)
    snprintf(command, 256, "cd /etc/%s", folder);
    system(command);
    memset(command, 0, 256);
    
    snprintf(command, 256, "sudo make %s", name);
    system(command);
    memset(command, 0, 256);
    
    snprintf(command, 256, "sudo mv %s.py %s", name, name);
    system(command);
    memset(command, 0, 256);
    
    snprintf(command, 256, "sudo cp /etc/%s/%s /usr/local/bin", folder, name);
    system(command);
    memset(command, 0, 256);
    return 0;
}

int update_program() {
    // choose progam version
    char version[256];
    char dec;
    
    install_folder();
    
    printf("\n");
    snprintf(command, 256, "cd /etc/%s", folder);
    system(command);
    memset(command, 0, 256);
    
    system("git tag");
    printf("Your current version is: ");
    system("git describe --tags");
    system("please choose version: ");
    fgets(version, 256, stdin);
    printf("\nDo you really want to change version? (y/n)  ");
    dec = getch();
    printf("\n");
    
    if (dec == 'y' || dec == 'Y' || dec == 'j') {
        
        snprintf(command, 256, "git checkout %s", version);
        system(command);
        memset(command, 0, 256);
        
        install_exec();
        uninstall_folder;
        printf("updated program");
    }
    
    printf("press any key to continue");
    getch();
    return 0;
}

int install_program() {
    // install program (first master)
    char dec;
    
    printf("\nThe system will be updated.\n");
    printf("Do you really want to install %s? (y/n)  ", folder);
    dec = getch();
    
    if (dec == 'y' || dec == 'Y' || dec == 'j') {
        printf("\n");
        
        system("sudo apt-get install git");
        system("sudo apt-get install build-essential");
        
        install_folder();
        install_exec();
        
        printf("installed program\n");
        printf("Do you want to choose version? (y/n)  ");
        dec = getch();
        
        if (dec == 'y' || dec == 'Y' || dec == 'j') {
            update_program();
            return 0;
        }
        printf("\n");
        uninstall_folder();
    }
    
    printf("\npress any key to continue");
    getch();
    return 0;
}

int uninstall() {
    // uninstall program
    char dec;
    
    printf("\nDo you really want to uninstall %s? (y/n)  ", folder);
    dec = getch();
    
    if (dec == 'y' || dec == 'Y' || dec == 'j') {
        printf("\n");

        uninstall_folder();
        
        snprintf(command, 256, "sudo rm /usr/local/bin/%s", name);
        system(command);
        memset(command, 0, 256);
    
        printf("removed program");
    }
    
    printf("\npress any key to continue");
    getch();
    return 0;
}

/*
test_installation() {
    // what is installed and what not?
    if [ -x /usr/local/bin/$name ] && [ -d /etc/$folder ]
        then
            echo "$folder (folder) and $name (exec/file) are existing:"
            echo "$name installed"
        elif [ -x /usr/local/bin/$name ]
            then
                echo "only $name (exec/file) is existing"
        elif [ -d /etc/$folder ]
            then
                echo "only $folder (folder) is existing"
        else
            echo "$folder (folder) and $name (exec/file) are NOT existing:"
            echo "$name not installed"
    fi
    read -p "press ENTER to continue" 
    main
}
*/

int learn_more2() {
    // link to website for more information
    
    if (strcmp(learn_more, "") == 0) {
        printf("sorry, learning more is not possible\n");
        printf("no valid link\n");
    }
    
    else {
        snprintf(command, 256, "firefox %s", learn_more);
        system(command);
        memset(command, 0, 256);
    }
     
    return 0;
} 

int show_message() {
    // show message from programmer
    printf("\n%s", message);
    printf("\npress any key to continue");
    getch();
    return 0;
}

int menue2();

int menue1() {
    // menue if installed
    char dec;
    int shutdown;
    
    system("clear");
    printf("%s installed\n", name);
    printf("do you want to:\n");
    printf("update        (u)\n");
    printf("uninstall     (d)\n");
    //printf("test          (t)\n");
    printf("learn more    (h)\n");
    printf("message       (m)\n");
    printf("quit          (q)\n");
    
    printf(":");
    dec = getch();
    
    switch(dec) {
        case 'u': {
            update_program();
            break;
        }
        case 'd': {
            uninstall();
            break;
        }
        /*case 't': {
            test_installation();
            break;
        }*/
        case 'h': {
            learn_more2();
            break;
        }
        case 'q': {
            system("clear");
            return 1;
        }
        case 'o': {
            shutdown = menue2();
            return shutdown;
        }
        case 'm': {
            show_message();
            break;
        }
       /* default: {
            break;
            
        }*/
    }
    return 0;
}

int menue2() {
    // menue if not installed
    char dec;
    int shutdown;
    
    system("clear");
    printf("%s not installed\n", name);
    printf("do you want to:\n");
    printf("install       (i)\n");
    //printf("test          (t)\n");
    printf("learn more    (h)\n");
    printf("message       (m)\n");
    printf("quit          (q)\n");

    printf(":");
    dec = getch();
    
    switch(dec) {
        case 'i': {
            install_program();
            break;
        }
        /*case 't': {
            test_installation();
            break;
        }*/
        case 'h': {
            learn_more2();
            break;
        }
        case 'q': {
            system("clear");
            return 1;
        }
        case 'o': {
            shutdown = menue1();
            return shutdown;
        }
        case 'm': {
            show_message();
            break;
        }
       /* default: {
            break;
        }*/
    }
    return 0;
}

int choose_menue() {
    // test if installed or not
    int shutdown;
    
    system("cd /usr/local/bin");
    
    if (access(name, EXEC) == 0) {
        shutdown = menue1();
    }
    else {
        shutdown = menue2();
    }
    return shutdown;
}
    
int main() {
    // start
    int shutdown;
    
    do {
        shutdown = choose_menue();
    } while (shutdown == 0);
    
    return 0;
}