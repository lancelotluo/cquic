#include <stdio.h>

#include <iostream>

#include "base/at_exit.h"
#include "base/command_line.h"
#include "base/logging.h"
#include "base/run_loop.h"
#include "base/strings/string_number_conversions.h"
#include "net/base/ip_address.h"
#include "net/base/ip_endpoint.h"
#include "net/quic/core/quic_packets.h"
#include "net/quic/core/quic_config.h"

int32_t FLAGS_port = 6121;


int main(int argc, char* argv[]) {
  base::AtExitManager exit_manager;

  base::CommandLine::Init(argc, argv);
  base::CommandLine* line = base::CommandLine::ForCurrentProcess();

  logging::LoggingSettings settings;
  settings.logging_dest = logging::LOG_TO_SYSTEM_DEBUG_LOG;
  if (line->HasSwitch("h") || line->HasSwitch("help")) {
    const char* help_str =
        "Usage: quic_server [options]\n"
        "\n"
        "Options:\n"
        "-h, --help                  show this help message and exit\n"
        "--port=<port>               specify the port to listen on\n"
        "--quic_response_cache_dir  directory containing response data\n"
        "                            to load\n"
        "--certificate_file=<file>   path to the certificate chain\n"
        "--key_file=<file>           path to the pkcs8 private key\n";
    std::cout << help_str;
    exit(0);
  }


  net::QuicConfig config;
  /*
  net::QuicServer server(
      CreateProofSource(line->GetSwitchValuePath("certificate_file"),
                        line->GetSwitchValuePath("key_file")),
      config, net::QuicCryptoServerConfig::ConfigOptions(),
      net::AllSupportedVersions(), &response_cache);

  int rc = server.CreateUDPSocketAndListen(
      net::QuicSocketAddress(net::QuicIpAddress::Any6(), FLAGS_port));
  if (rc < 0) {
    return 1;
  }

  while (1) {
    server.WaitForEvents();
  }
*/
	printf("hello quic\n");
}
