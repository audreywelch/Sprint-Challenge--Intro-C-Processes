#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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

  // Print file path to check what's being returned
  printf("file to be opened: %s\n",argv[1]);

  // Open directory

  // Pointer for directory entry
  struct dirent *de;

  // Open the directory named in commandline, return a pointer of DIR type
  DIR *dr = opendir(argv[1]);

  // Check for errors
  if (dr == NULL) {
    printf("Could not open current directory\n");
    exit(1);
  }

  struct stat buf;

  // Repeatly read and print entries
  while ((de = readdir(dr)) != NULL) {

    

    char *a = ("%s\n", argv[1]);
    printf("a is %s\n", a);
    char *b = ("/");
    printf("b is %s\n", b);
    // char *b = ("%s", de->d_name);
    char *c = ("%s%s\n", a, b);
    printf("%s\n", c);

    char result[100] = "";
    char result = snprintf(result, sizeof(result), "%s: %s: %s", argv[1], b, de->d_name);

    printf("BLAH: %s\n", result);
    char *full_path = ("%s: %s: %s\n", argv[1], b, de->d_name);
    printf("full path for size: %s\n", full_path);

    stat(full_path, &buf);
    printf("file size is %lld\n", buf.st_size);

    // print the name of the file within the directory entry
    printf("%s\n", de->d_name);


  }

  // Close directory
  closedir(dr);

  return 0;
}




  // // Create space for array storing commandline string
  // char commandline[2048];

  // // Get input from the keyboard
  // fgets(commandline, sizeof(commandline), stdin);

  // // Print user input to check
  // printf("User passed in: %s\n", commandline);