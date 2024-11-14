# Fix Astarisk FreePBX NAT Issues

C++ Script (Framework) to fix Asterisk FreePBX NAT Issues.

# Configure Asterisk or FreePBX (sip.conf) or (pjsip.conf) file to handle NAT properly

# For Chan_SIP:

[general]

nat=force_rport,comedia

externip=<your_public_ip>  ; Replace with your public IP or dynamic DNS

localnet=192.168.1.0/255.255.255.0  ; Replace with your internal network settings


# For For PJSIP (Newer Versions):

[transport-udp]

type=transport

protocol=udp

bind=0.0.0.0

externip=<your_public_ip>

localnet=192.168.1.0/24  ; Replace with your internal network


# More Instructions

Make sure to replace <your_public_ip> with your actual public IP or dynamic DNS name and localnet with your internal network range.

2. FreePBX NAT Settings
3. In FreePBX, go to Settings > Asterisk SIP Settings:


Under General SIP Settings:

Set NAT to Yes.

Set IP Configuration to Static IP (if you have a static IP) or Dynamic IP (if you use DDNS).

Enter your External Address and Local Networks.

Chan_PJSIP Settings:


Go to Connectivity > Asterisk SIP Settings > PJSIP Settings.

Set NAT Traversal Support to Yes.

3. Firewall and Router Configuration
4. On your firewall/router:


Forward SIP (port 5060) and RTP (usually ports 10000–20000) to your FreePBX server.

If using FreePBX’s integrated firewall, ensure it’s configured to allow external SIP and RTP traffic.

# C++ Script to Enable NAT Settings on Linux (Specific to Asterisk Ports):

The following C++ script helps ensure that your system’s iptables rules are configured correctly to allow SIP and RTP traffic through NAT.

# Was this script helpful to you? Please donate:

I put a lot of work into these scripts so please donate if you can. Even $1 helps!

PayPal: alex@alexandermirvis.com

CashApp / Venmo: LynxGeekNYC

BitCoin: bc1q8sthd96c7chhq5kr3u80xrxs26jna9d8c0mjh7
