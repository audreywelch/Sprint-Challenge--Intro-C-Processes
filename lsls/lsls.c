#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  int i;

  printf("There are %d command line argument(s):\n", argc);

  // argv[0] is the file name
  for (i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }

  printf("file to be opened: %s\n",argv[1]);

  // // Create space for array storing commandline string
  // char commandline[2048];

  // // Get input from the keyboard
  // fgets(commandline, sizeof(commandline), stdin);

  // // Print user input to check
  // printf("User passed in: %s\n", commandline);

  // Open directory

  // Pointer for directory entry
  struct dirent *de;

  // Open the directory named in commandline, returning a pointer of DIR type
  DIR *dr = opendir(argv[1]);

  // Check for errors
  if (dr == NULL) {
    printf("Could not open current directory\n");
    exit(1);
  }

  de = readdir(dr);
  printf("%s\n", de->d_name);

  // Repeatly read and print entries
  while ((de = readdir(dr)) != NULL) {

    // print the name of the file within the directory entry
    printf("%s\n", de->d_name);
  }

  // Close directory
  closedir(dr);

  return 0;
}