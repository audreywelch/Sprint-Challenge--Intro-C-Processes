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

    // Concatenate full file path
    char *full_path[100];
    stpcpy(stpcpy(stpcpy(full_path, argv[1]), "/"), de->d_name);
    //printf("%s\n", full_path);

    // Get file sizes using the full file path
    stat(full_path, &buf);

    // print the size & name of the file within the directory entry
    printf("%lld - %s\n", buf.st_size, de->d_name);
  }

  // Close directory
  closedir(dr);

  return 0;
}
