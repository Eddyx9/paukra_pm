/* paukra_pm.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define EXEC  X_OK
#define YES !(strcmp(dec, "y\n")) || !(strcmp(dec, "Y\n")) || !(strcmp(dec, "yes\n")) || !(strcmp(dec, "Yes\n")) || !(strcmp(dec, "YES\n")) || !(strcmp(dec, "j\n"))

char command[255];

const char name[] = "btsoot";
const char folder[] = "btsoot";
const char repo[] = "github.com/paulkramme/btsoot";
const char learn_more[] = "git.paukra.com/open-source/btsoot";

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

int main();

void install_exec() {
    // install executable (c/py)
    snprintf(command, 255, "cd /etc/%s", folder);
    system(command);
    memset(command, 0, 255);
    
    system("apt-get install build-essential");
    
    snprintf(command, 255, "make %s", name);
    system(command);
    memset(command, 0, 255);
    
    snprintf(command, 255, "mv %s.py %s", name, name);
    system(command);
    memset(command, 0, 255);
    
    snprintf(command, 255, "cp %s /usr/local/bin", name);
    system(command);
    memset(command, 0, 255);
}

void update_system() {
    // update system
    system("apt-get update");
    system("apt-get upgrade");
    printf("updated system");
}

void update_program() {
    // choose progam version
    char version[32];
    char dec[5];
    char enter;
    
    snprintf(command, 255, "cd /etc/%s", folder);
    system(command);
    memset(command, 0, 255);
    
    system("git tag");
    printf("Your current version is: ");
    system("git describe --tags");
    fgets(version, 32, stdin);
    printf("Do you really want to change version? (y/n)  ");
    fgets(dec, 5, stdin);
    
    if (YES) {
        
        snprintf(command, 255, "git checkout %s", version);
        system(command);
        memset(command, 0, 255);
        
        update_system();
        install_exec();
        printf("updated program");
    }
    
    printf("press ENTER to continue");
    scanf("%c", &enter);
    main();
}

void install_program() {
    // install program (first master)
    char dec[5];
    char enter;
    
    printf("The system will be updated.\n");
    printf("Do you really want to install %s? (y/n)  ", folder);
    fgets(dec, 5, stdin);
    
    if (YES) {
        system("apt-get install git");
        update_system();
        system("cd /etc");
        
        snprintf(command, 255, "git clone %s", repo);
        system(command);
        memset(command, 0, 255);
        
        install_exec();
        printf("installed program");
        printf("Do you want to choose version? (y/n)  ");
        fgets(dec, 5, stdin);
        
        if (YES) {
            update_program();
        }
    }
    
    printf("press ENTER to continue");
    scanf("%c", &enter);
    main();
}

void uninstall() {
    // uninstall program
    char dec[5];
    char enter;
    
    printf("Do you really want to uninstall %s? (y/n)  ", folder);
    fgets(dec, 5, stdin);
    
    if (YES) {
        snprintf(command, 255, "rm -r /etc/%s", folder);
        system(command);
        memset(command, 0, 255);
        
        snprintf(command, 255, "rm /usr/local/bin/%s", name);
        system(command);
        memset(command, 0, 255);
    
        printf("removed program");
    }
    
    printf("press ENTER to continue");
    scanf("%c", &enter);
    main();
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

void learn_more2() {
    // link to website for more information
    
    if (!(strcmp(learn_more, ""))) {
        printf("sorry, learning more is not possible");
        printf("no valid link");
    }
    
    else {
        snprintf(command, 255, "firefox %s", learn_more);
        system(command);
        memset(command, 0, 255);
    }
     
    main();
} 

void menue2();

void menue1() {
    // menue if installed
    char dec;
    
    system("clear");
    printf("%s installed\n", name);
    printf("do you want to:\n");
    printf("update        (u)\n");
    printf("uninstall     (d)\n");
    //printf("test          (t)\n");
    printf("learn more    (h)\n");
    printf("quit          (q)\n");
    
    printf(": ");
    dec = getchar();
    
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
            //exit(0);
            break;
        }
        case 'm': {
            menue2();
            break;
        }
        default: {
            main();
            
        }
    }
}

void menue2() {
    // menue if not installed
    char dec;
    
    system("clear");
    printf("%s not installed\n", name);
    printf("do you want to:\n");
    printf("install       (i)\n");
    //printf("test          (t)\n");
    printf("learn more    (h)\n");
    printf("quit          (q)\n");

    printf(": ");
    dec = getchar();
    
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
            break;
        }
        case 'm': {
            menue1();
            break;
        }
        default: {
            main();
        }
    }
}

int main() {
    // test if installed or not
    system("cd /usr/local/bin");
    
    if (!(access(name, EXEC))) {
        menue1();
    }
    else {
        menue2();
    }
}