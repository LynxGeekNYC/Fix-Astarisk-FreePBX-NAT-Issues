#include <iostream>
#include <cstdlib>

void setupAsteriskNAT(const std::string& interface) {
    std::string command;

    // Enable IP forwarding for NAT traversal
    command = "sysctl -w net.ipv4.ip_forward=1";
    std::cout << "Enabling IP forwarding..." << std::endl;
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to enable IP forwarding." << std::endl;
        return;
    }

    // Set up MASQUERADE for the specified interface for outgoing packets
    command = "iptables -t nat -A POSTROUTING -o " + interface + " -j MASQUERADE";
    std::cout << "Setting up MASQUERADE on interface " << interface << "..." << std::endl;
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to set up MASQUERADE." << std::endl;
        return;
    }

    // Allow incoming SIP traffic on port 5060 (UDP and TCP)
    command = "iptables -A INPUT -p udp --dport 5060 -j ACCEPT";
    std::cout << "Allowing incoming SIP traffic on UDP port 5060..." << std::endl;
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to allow SIP traffic on port 5060 (UDP)." << std::endl;
        return;
    }
    command = "iptables -A INPUT -p tcp --dport 5060 -j ACCEPT";
    std::cout << "Allowing incoming SIP traffic on TCP port 5060..." << std::endl;
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to allow SIP traffic on port 5060 (TCP)." << std::endl;
        return;
    }

    // Allow RTP traffic (ports 10000-20000)
    command = "iptables -A INPUT -p udp --dport 10000:20000 -j ACCEPT";
    std::cout << "Allowing RTP traffic on UDP ports 10000-20000..." << std::endl;
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to allow RTP traffic on ports 10000-20000." << std::endl;
        return;
    }

    std::cout << "NAT configuration for Asterisk completed on interface " << interface << "." << std::endl;
}

int main() {
    std::string interface;
    std::cout << "Enter the network interface for NAT (e.g., eth0): ";
    std::cin >> interface;

    setupAsteriskNAT(interface);

    return 0;
}
