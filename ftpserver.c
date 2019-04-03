#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*for getting file size using stat()*/
#include<sys/stat.h>

/*for sendfile()*/
#include<sys/sendfile.h>

/*for O_RDONLY*/
#include<fcntl.h>

int main(int argc,char *argv[])
{
  struct sockaddr_in server, client;
  struct stat obj;
  
  struct stat st = {0};  // for mkdir
  int sock1, sock2;
  char buf[100], command[4], filename[20]; //changed
  char username[20];
	char password[20];
	char firstname[20];
	char pass[20];
  char string_0[256];
  int k, i, size, len, c;
  int filehandle;
  sock1 = socket(AF_INET, SOCK_STREAM, 0);
  if(sock1 == -1)
    {
      printf("Socket creation failed");
      exit(1);
    }
 bzero(&server, sizeof(server));
  server.sin_port = atoi(argv[1]);
  server.sin_addr.s_addr = 0;
  k = bind(sock1,(struct sockaddr*)&server,sizeof(server));
  if(k == -1)
    {
      printf("Binding error");
      exit(1);
    }
  k = listen(sock1,3);
  if(k == -1)
    {
      printf("Listen failed");
      exit(1);
    }
  len = sizeof(client);
  sock2 = accept(sock1,(struct sockaddr*)&client, &len);
  i = 1;
  while(1)
    {
      recv(sock2, buf, 100, 0);
      sscanf(buf, "%s", command);
      printf("command recieved %s \n",command);
  if(!strcmp(command, "USER"))
 {   c=0;
	  FILE *filePointer ; 
    filePointer= fopen("confidential.txt", "r+");
		sscanf(buf+5,"%s",username);
   	while((fgets(string_0,256,filePointer)) != NULL) {

  //scans the line then sets 1st and 2nd word to those variables
  sscanf(string_0,"%s",firstname);

  if(strcmp(firstname,username)==0){
			c = 331;
    printf("A match has been found");
  }
}
		fclose(filePointer);
	
     send(sock2, &c, sizeof(int), 0);


 }
    else   if(!strcmp(command, "PASS"))
 {   c=0;
	  FILE *filePointer ; 
    filePointer= fopen("confidential.txt", "r+");
		sscanf(buf+5,"%s",password);
   	while((fgets(string_0,256,filePointer)) != NULL) {

  //scans the line then sets 1st and 2nd word to those variables
  sscanf(string_0,"%s %s",firstname,pass);

  if(strcmp(firstname,username)==0 && strcmp(pass,password)==0){
			c = 331;
    printf("A match has been found");
  }
}
		fclose(filePointer);
	
     send(sock2, &c, sizeof(int), 0);


 }
    else 
 if(!strcmp(command, "CRET"))
 {   
	  FILE *filePointer ; 
    filePointer= fopen("confidential.txt", "a");
   	fputs(buf+5,filePointer);
		fputs("\n",filePointer);
		fclose(filePointer);
		   
		c = 1;
	
     send(sock2, &c, sizeof(int), 0);


 }
    else  if(!strcmp(command, "LIST"))
	{
	  system("ls >temps.txt");
	  i = 0;
	  stat("temps.txt",&obj);
	  size = obj.st_size;
	  send(sock2, &size, sizeof(int),0);
	  filehandle = open("temps.txt", O_RDONLY);
	  sendfile(sock2,filehandle,NULL,size);
	}
      else if(!strcmp(command,"RETR"))
	{
	  sscanf(buf, "%s%s", filename, filename);
	  stat(filename, &obj);
	  filehandle = open(filename, O_RDONLY);
	  size = obj.st_size;
	  if(filehandle == -1)
	      size = 0;
	  send(sock2, &size, sizeof(int), 0);
	  if(size)
	  sendfile(sock2, filehandle, NULL, size);
      
	}
      else if(!strcmp(command, "STOR"))
        {
	  int c = 0, len;
	  char *f;
	  sscanf(buf+strlen(command), "%s", filename);
	  recv(sock2, &size, sizeof(int), 0);
	  i = 1;
	  while(1)
	    {
	      filehandle = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666);
	      if(filehandle == -1)
		{
		  sprintf(filename + strlen(filename), "%d", i);
		}
	      else
		break;
	    }
	  f = malloc(size);
	  recv(sock2, f, size, 0);
	  c = write(filehandle, f, size);
	  close(filehandle);
	  send(sock2, &c, sizeof(int), 0);
        }
      else if(!strcmp(command, "PWD"))
	{
	  system("pwd>temp.txt");
	  i = 0;
          FILE*f = fopen("temp.txt","r");
          while(!feof(f))
            buf[i++] = fgetc(f);
          buf[i-1] = '\0';
	  fclose(f);
          send(sock2, buf, 100, 0);
	}
      else if(!strcmp(command, "CWD"))
        { printf("executing command cd \n ");
          
          if(chdir(buf+3) == 0)
	    c = 1;
	  else
	    c = 0;
          send(sock2, &c, sizeof(int), 0);
         printf("\ncd executed");
        }
      
      //user , pass , mkd ,rmd , abor 

     else if(!strcmp(command, "MKD"))
	{
	  
	  printf("executing command mkdir \n ");
          
          if(mkdir(buf+4, 0700) == 0)
	    c = 1;
	  else
	    c = 0;
          send(sock2, &c, sizeof(int), 0);	
		

	}
        else if(!strcmp(command, "RMD"))
	{
	  printf("executing command rmdir \n ");
          
          if(rmdir(buf+4) == 0)
	    c = 1;
	  else
	    c = 0;
          send(sock2, &c, sizeof(int), 0);	
		

	}



      else if(!strcmp(command, "bye") || !strcmp(command, "QUIT"))
	{
	  printf("FTP server quitting..\n");
	  i = 1;
	  send(sock2, &i, sizeof(int), 0);
	  exit(0);
	}
	else {
		char *msg="NO SUCH COMMAND";
		 send(sock2, &msg, sizeof(int), 0);
	}
	 
    }
  return 0;
}


