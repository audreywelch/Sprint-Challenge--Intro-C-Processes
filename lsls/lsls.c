#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char commandline[2048];

  // Get input from the keyboard
  fgets(commandline, sizeof(commandline), stdin);

  // Print user input to check
  printf("User passed in: %s\n", commandline);

  // Open directory

  // pointer for directory entry
  struct dirent *de;

  // Open the directory, returning a pointer of DIR type
  // DIR *opendir(char *path);
  
  DIR *dr = opendir(commandline);
  if (dr = NULL) {
    printf("Could not open current directory");
    return 0;
  }
  while ((de = readdir(dr)) != NULL) {
    printf("%s\n", de->d_name);
  }
  

  // // Repeatly read and print entries

  // // Close directory
  // closedir(dr);

  return 0;
}