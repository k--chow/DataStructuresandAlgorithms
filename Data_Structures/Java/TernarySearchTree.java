package Model;
import java.util.*;

public class TernarySearchTree {
  private Node root;

  public TernarySearchTree()
  {
    this.root = null;
  }
  //insert
  public void insert(String s, int pos, Node node)
  {
    //System.out.println(s.charAt(pos));
    if (this.root == null) {
      this.root = new Node(s.charAt(pos), false);
      node = this.root;
    }
    if (s.charAt(pos) < node.getValue()) {
      if (node.getLeft() == null) node.setLeft(new Node(s.charAt(pos), false));
      insert(s, pos, node.getLeft());
    } else if (s.charAt(pos) > node.getValue()) {
      if (node.getRight() == null) node.setRight(new Node(s.charAt(pos), false));
      insert(s, pos, node.getRight());
    } else if (pos + 1 == s.length()) {
      node.setIsWord(true);
    } else {
      if (node.getMid() == null) node.setMid(new Node(s.charAt(pos + 1), false));
      insert(s, pos + 1, node.getMid());
    }
  }
  //contains
  public boolean contains(String s, int pos, Node node)
  {
    if (node == null) return false;
    if (s.charAt(pos) < node.getValue()) {
      return contains(s, pos, node.getLeft());
    } else if (s.charAt(pos) > node.getValue()) {
      return contains(s, pos, node.getRight());
    } else if (pos + 1 == s.length()) {
      if (node.getIsWord()) {
        return true;
      }
    } else {
      return contains(s, pos+1, node.getMid());
    }
    return false;



  }

  //suggest

  //getRoot
  public Node getRoot()
  {
    return this.root;
  }

  public void printTree(Node n) {
    System.out.println(n.getValue());
    if (n.getLeft() != null) {
      System.out.println("left of " + n.getValue());
      printTree(n.getLeft());
    }

    if (n.getMid() != null ) {
      System.out.println("mid of " + n.getValue());
      printTree(n.getMid());
    }

    if (n.getRight() != null) {
      System.out.println("right of " + n.getValue());
      printTree(n.getRight());
    }
  }
}
