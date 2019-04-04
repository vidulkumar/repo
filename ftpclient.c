/*FTP Client*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*for getting file size using stat()*/
#include<sys/stat.h>

/*for sendfile()*/
#include<sys/sendfile.h>

/*for O_RDONLY*/
#include<fcntl.h>

void errormsg(int error)
{
 if(error==530)
   printf("530 :YOU are not logged in ");
else if(error==331)
   printf("331 :username exists password needed ");
else if(error==332)
   printf("332 :NO USER FOUND ");
	 	 

}


int main(int argc,char *argv[])
{
  struct sockaddr_in server;
  struct stat obj;
  int sock;
  int choice;
  char buf[100], command[5], filename[20], *f,text[20];
  int k, size, status;
  int filehandle;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == -1)
    {
      printf("socket creation failed");
      exit(1);
    }
  server.sin_family = AF_INET;
  server.sin_port = atoi(argv[1]);
  server.sin_addr.s_addr = 0;
  k = connect(sock,(struct sockaddr*)&server, sizeof(server));
  if(k == -1)
    {
      printf("Connect Error");
      exit(1);
    }
  int i = 1;
  while(1)
    {
      printf("---------------------\n");
			gets(text);
if (strncmp(text,"USER",4)==0) {
		    strcpy(buf, text);
			  send(sock, buf, 100, 0);
	      recv(sock, &status, sizeof(int), 0);
		    if(status)
	       errormsg(status);
	      else
	       printf("error\n");
	}
			
else if (strncmp(text,"PASS",4)==0) {
		    strcpy(buf, text);
			  send(sock, buf, 100, 0);
	      recv(sock, &status, sizeof(int), 0);
		    if(status)
	        printf("logged in\n");
	      else
	        printf("error\n");
	}
			
else 
	if (strncmp(text,"CRET",4)==0) {
		strcpy(buf, text);
			  send(sock, buf, 100, 0);
	    recv(sock, &status, sizeof(int), 0);
	  	if(status==1)
	    printf("user created successfully\n");
	    else
	    printf("error\n");
	}
			
else  if(strncmp(text,"RETR",4)==0)
	{
	  strcpy(buf, text);

		sscanf(text, "%s%s", filename, filename);
		printf("filename is : %s",filename);
	  send(sock, buf, 100, 0);
	  recv(sock, &size, sizeof(int), 0);
	  if(size==530)
		{
			errormsg(size);
		}
		else if(!size)
	    {
	      printf("No such file on the remote directory\n\n");
	    break;
	    }
	  f = malloc(size);
	  recv(sock, f, size, 0);
	  while(1)
	    {
	      filehandle = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666);
	      if(filehandle == -1)
	     	{
		     sprintf(filename + strlen(filename), "%d", i);//needed only if same directory is used for both server and client
	   	  }
	      else break;
	    }
	  write(filehandle, f, size, 0);
	  close(filehandle);
	  strcpy(buf, "cat ");
	  strcat(buf, filename);
	  system(buf);
	}
	else if(strncmp(text,"STOR",4)==0)
	{
	  strcpy(buf, text);
		sscanf(text, "%s%s", filename, filename);
	  filehandle = open(filename, O_RDONLY);
          if(filehandle == -1)
            {
              printf("No such file on the local directory\n\n");
              break;
            }
         // strcpy(buf, "STOR ");
	  //strcat(buf, filename);
	  send(sock, buf, 100, 0);
	  stat(filename, &obj);
	  size = obj.st_size;
	  send(sock, &size, sizeof(int), 0);
	  sendfile(sock, filehandle, NULL, size);
	  recv(sock, &status, sizeof(int), 0);
	  if(status)
	    printf("File stored successfully\n");
	  else
	    printf("File failed to be stored to remote machine\n");
	}
else if(strncmp(text,"PWD",3)==0)
	{
	       strcpy(buf, text);
	       send(sock, buf, 100, 0);
	       recv(sock, buf, 100, 0);
				 if(buf==530)
				 { errormsg(530);}
				 else
				 {
					
	       printf("The path of the remote directory is: %s\n", buf);
				 }
		}
else if(strncmp(text,"LIST",4)==0)
	{
	        strcpy(buf, "LIST");
          send(sock, buf, 100, 0);
	        recv(sock, &size, sizeof(int), 0);
       if(size==530)
			 {errormsg(size);}
			 else{

          f = malloc(size);
          recv(sock, f, size, 0);
	        filehandle = creat("temp.txt", O_WRONLY);
	        write(filehandle, f, size, 0);
	        close(filehandle);
          printf("The remote directory listing is as follows:\n");
	        system("cat temp.txt");
			 }
	}
else if(strncmp(text,"CWD",3)==0)
	{
	        strcpy(buf, text);
          send(sock, buf, 100, 0);
          printf("\ndata sent");
	        recv(sock, &status, sizeof(int), 0);
          if(status==1)
            printf("Remote directory successfully changed\n");
          else
            errormsg(status);
          break;
 	}
else if(strncmp(text,"MKD ",4)==0)
	{      
	        strcpy(buf, text);
          send(sock, buf, sizeof(buf), 0);
          printf("\ndata sent");
	        recv(sock, &status, sizeof(int), 0);
          if(status==1)
            printf("Remote directory successfully created\n");
          else
            errormsg(status);
   	}
else if(strncmp(text,"RMD ",4)==0)
	{      
	        strcpy(buf, text);
          send(sock, buf, sizeof(buf), 0);
          printf("\ndata sent");
	        recv(sock, &status, sizeof(int), 0);
          if(status==1)
            printf("Remote directory successfully deleted\n");
          else
            errormsg(status);
   	}
else if(strncmp(text,"ABOR",4)==0)
	{      strcpy(buf, text);
          send(sock, buf, 100, 0);


          recv(sock, &status, 100, 0);
	       if(status)
	        {
	         printf("Session reset\n");
	        }
	    	 else	
	       { errormsg(status); }
	} 
	else if(strncmp(text,"QUIT",4)==0)
	{       strcpy(buf, text);
          send(sock, buf, 100, 0);
          recv(sock, &status, 100, 0);
	       if(status)
	        {
	          printf("Server closed\nQuitting..\n");
	          exit(0);
	        }
	        printf("Server failed to close connection\n");
	}
else{
	        status =502;
		      errormsg(status);
    }

    }
}
