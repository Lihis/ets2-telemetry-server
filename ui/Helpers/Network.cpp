#include "Network.h"
#ifdef _WIN32
#define WINVER 0x0600
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#else
#include <ifaddrs.h>
#include <netdb.h>
#endif

namespace Network {
    std::vector<IFace> get_interfaces() {
        std::vector<IFace> interfaces = {};

#ifdef _WIN32
        DWORD dwRetVal = 0;
        ULONG outBufLen = 15000;
        ULONG Iterations = 0;
        PIP_ADAPTER_ADDRESSES pAddresses = nullptr;
        PIP_ADAPTER_ADDRESSES pCurrAddresses = nullptr;

        do {
            pAddresses = static_cast<IP_ADAPTER_ADDRESSES *>(HeapAlloc(GetProcessHeap(), 0, outBufLen));
            if (!pAddresses) {
                break;
            }

            dwRetVal = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, nullptr, pAddresses, &outBufLen);
            if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
                HeapFree(GetProcessHeap(), 0, pAddresses);
                pAddresses = nullptr;
            } else {
                break;
            }

            Iterations++;
        } while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < 3));

        if (dwRetVal == NO_ERROR) {
            pCurrAddresses = pAddresses;
            while (pCurrAddresses) {
                PIP_ADAPTER_UNICAST_ADDRESS pUnicast;

                pUnicast = pCurrAddresses->FirstUnicastAddress;
                while (pUnicast) {
                    if (pUnicast->Address.lpSockaddr->sa_family == AF_INET) {
                        DWORD addr_len = 255;
                        WCHAR addr[addr_len + 1];

                        if (WSAAddressToStringW(
                                pUnicast->Address.lpSockaddr,
                                pUnicast->Address.iSockaddrLength,
                                nullptr,
                                addr,
                                &addr_len) == 0)
                        {
                            interfaces.emplace_back(IFace(addr, pCurrAddresses->FriendlyName));
                        }
                    }
                    pUnicast = pUnicast->Next;
                }
                pCurrAddresses = pCurrAddresses->Next;
            }
        }

        if (pAddresses) {
            HeapFree(GetProcessHeap(), 0, pAddresses);
        }
#else
        struct ifaddrs *ifaddr;
        struct ifaddrs *ifa;
        int i;

        if (getifaddrs(&ifaddr) != -1) {
            for (ifa = ifaddr, i = 0; ifa != nullptr; ifa = ifa->ifa_next, i++) {
                if (ifa->ifa_addr == nullptr) {
                    continue;
                }

                char host[NI_MAXHOST];
                if (ifa->ifa_addr->sa_family == AF_INET) {
                    if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, nullptr, 0, NI_NUMERICHOST) == 0) {
                        interfaces.emplace_back(IFace(host, ifa->ifa_name));
                    }
                }
            }
        }
#endif

        return interfaces;
    }

    std::string get_addr(const wxString &iface) {
        std::string addr;

        for (const auto &i : get_interfaces()) {
            if (i.name == iface) {
                addr = i.addr;
                break;
            }
        }

        return addr;
    }
} // namespace Network
