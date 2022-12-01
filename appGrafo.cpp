/*
 * appGrafo.cpp
 *
 *  Created on: 01/12/2022
 *      Author: Francisco Couttolenc Ortiz
 */
#include <iostream>
#include <cstring>
#include "ugraph.h"
#include "wgraph.h"
#include <vector>
#include <algorithm>

//Complexity: O(n)
int BFS1(WMatrixGraph<char, int> wmg3, WListGraph<char, int> wlg3, std::vector<char> vertex_list)
{
	bool flag = 1;
	char temp;
	while (flag)
	{
		std::cout << "Select BFS Starting Vertex: ";
		std::cin >> temp;
		if (std::count(vertex_list.begin(), vertex_list.end(), temp))
		{
			std::cout << "BFS (" << temp << ") ->\t";
			std::set<char, std::less<char>, std::allocator<char>> edges = bfs(temp, &wmg3);
			for (std::_Rb_tree_const_iterator<char> itr = edges.begin(); itr != edges.end(); itr++)
			{
				std::cout << (*itr) << "\t";
			}
			std::cout << "\n\n";
			flag = 0;
		}
		else
		{
			std::cout << "origin not found. Try another one.\n";
		}
	}
}

// Complexity: O(n)
int DFS1(WMatrixGraph<char, int> wmg3, WListGraph<char, int> wlg3, std::vector<char> vertex_list)
{
	bool flag= 1;
	char temp;
	while(flag){
		std::cout << "Select DFS Starting Vertex: ";
		std::cin >> temp;
		if (std::count(vertex_list.begin(), vertex_list.end(), temp))
		{
			std::cout << "DFS (" << temp << ") ->\t";
			std::set<char, std::less<char>, std::allocator<char>> edges = dfs(temp, &wmg3);
			for (std::_Rb_tree_const_iterator<char> itr = edges.begin(); itr != edges.end(); itr++)
			{
				std::cout << (*itr) << "\t";
			}
			std::cout << "\n\n";
			flag = 0;
		}
		else
		{
			std::cout << "Origin not found. Try another one.\n";
		}
	}
	BFS1(wmg3, wlg3, vertex_list);
};

// Complexity: O(n)
int main(int argc, char *argv[])
{

	int num_edges, num_vertexes, ne_t;
	char temp;
	std::vector<char> vertex_list = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	std::cout << "Insert Total Vertexes: ";
	std::cin >> num_vertexes;
	WMatrixGraph<char, int> wmg3(num_vertexes, 0);
	WListGraph<char, int> wlg3;
	std::cout << "Insert Total Arc's: ";
	std::cin >> num_edges;
	ne_t = num_edges;
	for(int c = 0; c <= num_vertexes; c++){
		while(ne_t!=0){
			std::cout << "\nInsert Arc's Destination: " << vertex_list[c] << " -> ___ \n";
			std::cout << "(Insert Origin as Destination to change Origin): ";
			std::cin >> temp;
			if (temp != vertex_list[c])
			{
				if (std::count(vertex_list.begin(), vertex_list.end(), temp))
				{
					wmg3.addEdge(vertex_list[c], temp, 1);
					wlg3.addEdge(vertex_list[c], temp, 1);
					ne_t--;
				}
				else
				{
					std::cout << "Destination not found. Try another one.\n";
				}


			}
			else{
				break;
			}
		}
	}
	std::cout << "\nMatrix Representation of Graph:\n\n"<<wmg3.toString();
	std::cout << "\nList Representation of Graph:\n\n";
	for(int c = 0;c<=num_edges;c++){
		std::map<char, int> wedges = wmg3.getConnectionFrom(vertex_list[c]);
		std::map<char, int>::iterator witr3;

		std::cout << vertex_list[c] << "\t";
		for (witr3 = wedges.begin(); witr3 != wedges.end(); witr3++)
		{
			std::cout << "(" << witr3->first << "," << witr3->second << ")\t";
		}
		std::cout << "\n\n";
	}
	DFS1(wmg3, wlg3, vertex_list);
}
