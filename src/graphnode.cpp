#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode()
{
    // delete _chatBot;
    // prevent _chatBot from deleting more than once
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(std::move(edge));
}

void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot); // construct _chatBot by move assignment
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index)
{

    return _childEdges[index].get();
}