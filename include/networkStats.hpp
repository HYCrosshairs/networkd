/*******************************************************************************
*
*   Name:        networkStats.hpp
*   Date:        08/28/2021
*   Author:      Hacene YOUNSI
*
*   (C) Copyright 2021 Fennec Software Inc., See the license
*******************************************************************************/

#pragma once

namespace monitor {
namespace network {

struct RX
{
    long unsigned int bytes; // total bytes received
    long unsigned int packets; // total packets received
    long unsigned int errors; // bad packets received
    long unsigned int dropped; // no space in linux buffers
    long unsigned int length_errors;
    long unsigned int over_errors; // receiver ring buff overflow
    long unsigned int crc_errors; // recved pkt with crc error
    long unsigned int frame_errors; // recv'd frame alignment error
    long unsigned int fifo_errors; // recv'r fifo overrun
    long unsigned int missed_errors; // receiver missed packet
    long unsigned int compressed;
};

struct TX
{
    long unsigned int bytes; // total bytes transmitted
    long unsigned int packets; // total packets transmitted
    long unsigned int errors; // packet transmit problems
    long unsigned int dropped; // no space available in linux
    long unsigned int aborted_errors;
    long unsigned int carrier_errors;
    long unsigned int fifo_errors;
    long unsigned int heartbeat_errors;
    long unsigned int window_errors;
    long unsigned int compressed;
};

struct NetworkStats
{
    TX tx;
    RX rx;
    long unsigned int multicast; /* multicast packets received	*/
    long unsigned int collisions;
};

constexpr char NETWORK_STATS_PATH[] = "/proc/net/dev";
constexpr char NETWORK_STATS_DATA[] = "/tmp/dNetworkStatsData.txt"

class NetworkStats
{
    NetworkStats() = delete;
};

} // namespace network
} // namespace monitor