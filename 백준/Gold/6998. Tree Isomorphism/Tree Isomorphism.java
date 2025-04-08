import java.util.*;

public class Main {
    static class Node {
        List<Node> children = new ArrayList<>();
    }

    static Node parseTree(Iterator<String> it) {
        it.next(); // 노드 이름 무시
        Node node = new Node();
        while (it.hasNext()) {
            String token = it.next();
            if (token.equals("#")) {
                break;
            } else {
                node.children.add(parseTree(new IteratorWithCurrent(token, it)));
            }
        }
        return node;
    }

    static String normalize(Node node) {
        if (node.children.isEmpty()) return "()";
        List<String> normalizedChildren = new ArrayList<>();
        for (Node child : node.children) {
            normalizedChildren.add(normalize(child));
        }
        Collections.sort(normalizedChildren);
        return "(" + String.join("", normalizedChildren) + ")";
    }

    static class IteratorWithCurrent implements Iterator<String> {
        private String current;
        private Iterator<String> base;

        IteratorWithCurrent(String current, Iterator<String> base) {
            this.current = current;
            this.base = base;
        }

        @Override
        public boolean hasNext() {
            return current != null || base.hasNext();
        }

        @Override
        public String next() {
            if (current != null) {
                String tmp = current;
                current = null;
                return tmp;
            }
            return base.next();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(sc.nextLine());

        for (int t = 0; t < T; t++) {
            String[] tree1Tokens = sc.nextLine().split(" ");
            String[] tree2Tokens = sc.nextLine().split(" ");

            Node root1 = parseTree(Arrays.asList(tree1Tokens).iterator());
            Node root2 = parseTree(Arrays.asList(tree2Tokens).iterator());

            if (normalize(root1).equals(normalize(root2))) {
                sb.append("The two trees are isomorphic.\n");
            } else {
                sb.append("The two trees are not isomorphic.\n");
            }
        }

        System.out.println(sb);
    }
}
