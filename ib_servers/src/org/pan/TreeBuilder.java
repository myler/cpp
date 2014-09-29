package org.pan;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;

/**
 * Created by yigli on 14-6-23.
 */
public class TreeBuilder {

	private List<Entry> treeList = null;

	List<Map<String, String>> treeNodes = new ArrayList();

	public static void main(String args[]) {
		TreeBuilder a = new TreeBuilder();
		a.getTreeNodeList();
	}

	public List<Map<String, String>> getTreeNodeList() {

		ExcelLoader loader = new ExcelLoader(
				"/home/myl/ib_server/5480614Rev3.xlsx");

		List<List<String>> rows = loader.loadData(0);

		treeList = new ArrayList<Entry>(rows.size());

		XMLElement data = new XMLElement();
		List<String> rootRow = rows.get(7);
		data.xmlbegin = String
				.format("<bom level='%s' type='%s' name='%s' Revision='%s'>\n",
						rootRow.get(0), rootRow.get(1), rootRow.get(2), rootRow
								.get(3));
		data.xmlend = "</bom>\n";
		treeList.add(new Entry(0, data));

		for (List<String> row : rows.subList(8, rows.size())) {
			treeList.add(new Entry(Integer.valueOf(row.get(1)),
					toXMLElement(row)));
		}

		TreeNode root = this.build();
		Document doc;
		try {

			doc = DocumentHelper.parseText(root.toXMLString());
			Element rootElt = doc.getRootElement(); // ��ȡ��ڵ�
			// for()
			// PrintWriter w = new PrintWriter(new FileWriter(
			// "c:\\work\\1TY\\bom2xml\\5480614Rev3.xml"));
			//
			// root.toXML(w);
			this.toList("root0", rootElt);
			// System.out.println(root.toXMLString());
			// System.out.println("--------------------------");
			// System.out.println(treeNodes.toString());
		} catch (DocumentException e1) {
			e1.printStackTrace();
		} // ���ַ�תΪXML

		return treeNodes;
	}

	public int id = 0;

	public void toList(String parentid, Element parent) {
		List<Element> childs = parent.elements();
		for (int i = 0; i < childs.size(); i++) {
			Element node = childs.get(i);
			String idStr = String.valueOf(id++);

			Map<String, String> nodeMap = new HashMap();
			nodeMap.put("id", idStr);
			nodeMap.put("parentid", parentid);
			if ("5124332-A".equals(node.attributeValue("name"))) {
				System.out.println("1111");
			}
			nodeMap.put("text", node.attributeValue("name")
					+ "&nbsp;&nbsp;&nbsp;" + node.attributeValue("desc"));
			treeNodes.add(nodeMap);
			if (node.elements().size() > 0) {
				toList(idStr, node);
			}
		}
	}

	// static private
	private XMLElement toXMLElement(List<String> row) {
		XMLElement ret = new XMLElement();
		ret.xmlbegin = String
				.format(
						"<bom level='%s' marknum='%s' type='%s' name='%s' revision='%s' state='%s' uom='%s' quantity='%s' desc='%s' rdo='%s'>\n",
						row.get(1), row.get(2), row.get(4), row.get(5), row
								.get(6), row.get(7), row.get(8), row.get(9),
						row.get(10), row.get(13));
		ret.xmlbody = String
				.format(
						"<bom level='%s' marknum='%s' type='%s' name='%s' revision='%s' state='%s' uom='%s' quantity='%s' desc='%s' rdo='%s'/>\n",
						row.get(1), row.get(2), row.get(4), row.get(5), row
								.get(6), row.get(7), row.get(8), row.get(9),
						row.get(10), row.get(13));

		ret.xmlend = String.format("</bom>\n");

		return ret;
	}

	public TreeNode build() {
		if (treeList == null || treeList.isEmpty()) {
			return null;
		}


		if (treeList.size() == 1) {
			return new TreeNode(treeList.get(0).treeLevel, treeList.get(0).data);
		}

		TreeNode ret = new TreeNode(treeList.get(0).treeLevel,
				treeList.get(0).data);

		ret.setChildren(builchild(treeList.subList(1, treeList.size())));

		return ret;
	}

	List<TreeNode> builchild(List<Entry> treeList) {
		if (treeList.isEmpty()) {
			return null;
		}

		if (treeList.size() == 1) {
			List<TreeNode> ret = new ArrayList<TreeNode>();
			ret.add(new TreeNode(treeList.get(0).treeLevel,
					treeList.get(0).data));

			return ret;
		}

		int index = findSubtree(treeList);

		if (index == -1) {
			TreeNode node = new TreeNode(treeList.get(0).treeLevel, treeList
					.get(0).data);
			List<TreeNode> children = builchild(treeList.subList(1, treeList
					.size()));

			node.setChildren(children);
			List<TreeNode> ret = new ArrayList<TreeNode>();

			ret.add(node);

			return ret;
		}

		List<TreeNode> ret = new ArrayList<TreeNode>();

		List<Entry> first = treeList.subList(0, index);
		List<Entry> last = treeList.subList(index, treeList.size());

		ret.addAll(builchild(first));
		ret.addAll(builchild(last));
		return ret;
	}

	private int findSubtree(List<Entry> list) {

		if (list == null || list.size() < 2) {
			return -1;
		}
		int first = list.get(0).treeLevel;

		int subindex = 1;

		while (subindex < list.size()) {
			int sub = list.get(subindex).treeLevel;
			if (sub != first) {
				subindex++;
			} else {
				return subindex;
			}
		}
		return -1;
	}
}
