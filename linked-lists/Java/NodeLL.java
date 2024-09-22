public class NodeLL {
    private int val;
    private NodeLL next;

    public NodeLL(int val, NodeLL next) {
        this.val = val;
        this.next = next;
    }

    public NodeLL(int val) {
        this(val, null);
    }

    public NodeLL() {
        this(0);
    }

    public int getVal() {
        return this.val;
    }

    public NodeLL getNext() {
        return this.next;
    }
}