//udpsocket - https://www.codejava.net/java-se/networking/java-udp-client-server-program-example

// Server : 

import java.net.*;
import java.util.*;

public class UDPServer {

public
    static void main(String[] args)

    {

        byte[] receiveBytes = new byte[1024];

        System.out.println("Server is ready for chatting (Type 'bye' to stop chat)");
        try(DatagramSocket ds = new DatagramSocket(1309); Scanner sc = new Scanner(System.in);)
        {

            while (!ds.isClosed())

            {

                // Construct Datagram packet to receive message

                DatagramPacket dp = new DatagramPacket(receiveBytes, receiveBytes.length);
                ds.receive(dp);
                String dataString = new String(dp.getData());
                System.out.println("Client :" + dataString);
                String input = sc.nextLine();
                if (input.trim().equalsIgnoreCase("bye"))

                {

                    System.out.println("Chat has been terminated from Server side");

                    break;
                }

                // Construct Datagram packet to send message

                DatagramPacket sendPacket = new DatagramPacket(input.getBytes(), input.getBytes().length, dp.getAddress(), dp.getPort());
                ds.send(sendPacket);
            }

            ds.close();
        }

        catch (Exception e)

        {

    e.p rintStackTrace();
}}

}

// Client :

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPClient

{

public
    static void main(String[] args)

    {

        byte[] receiveBytes = new byte[1024];

        System.out.println("Client is ready for Chatting (Type 'bye' to stop chat)");
        try(Scanner sc = new Scanner(System.in); DatagramSocket ds = new DatagramSocket();)
        {

            // Get server address

            ﬁnal InetAddress SERVER_ADDRESS = InetAddress.getLocalHost();
            DatagramPacket dataPacket = null;
            while (!ds.isClosed())

            {

                String input = sc.nextLine();

                // Terminate the client if user says "bye" if (input.trim().equalsIgnoreCase("bye"))
                {

                    System.out.println("Chat has been terminated from Client side");
                    break;
                }

                // Construct Datagram packet to send message

                dataPacket = new DatagramPacket(input.getBytes(), input.getBytes().length, SERVER_ADDRESS, 1309);
                ds.send(dataPacket);

                // Construct Datagram packet to receive message

                dataPacket = new DatagramPacket(receiveBytes, receiveBytes.length);
                ds.receive(dataPacket);
                System.out.println("Server :" + new String(receiveBytes));
            }
        }

        catch (IOException e)

        {

            e.printStackTrace();
        }
    }
}
