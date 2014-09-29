package ibservice.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.mail.DefaultAuthenticator;
import org.apache.commons.mail.HtmlEmail;

public class SendMailServlet extends HttpServlet {

	/**
	 * The doGet method of the servlet. <br>
	 * 
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request
	 *            the request send by the client to the server
	 * @param response
	 *            the response send by the server to the client
	 * @throws ServletException
	 *             if an error occurred
	 * @throws IOException
	 *             if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HtmlEmail email = new HtmlEmail();
		email.setHostName("smtp.163.com");
		email.setSmtpPort(25);
		email.setAuthenticator(new DefaultAuthenticator("ibservice",
				"service123456"));
		StringBuilder sb = new StringBuilder(1024);
		try {
			sb
					.append("\t\t\t\t\t<table width=\"500\" style=\"border-collapse: collapse;\" border=\"1\"\r\n");
			sb.append("\t\t\t\t\t\tcellpadding=\"0\" cellspacing=\"0\">\r\n");
			sb.append("\t\t\t\t\t\t");

			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(
					"jdbc:oracle:thin:@localhost:1521:orcl", "ta4_1", "ta4_1");
			Statement stmt = conn.createStatement();
			String sql = "select * from cso_report order by year desc,to_number(substr(FW,3,2)) desc";
			ResultSet rs = stmt.executeQuery(sql);
			ResultSetMetaData metaData = rs.getMetaData();
			int size = metaData.getColumnCount();

			sb.append("\r\n");
			sb.append("\t\t\t\t\t\t<tr>\r\n");
			sb
					.append("\t\t\t\t\t\t\t<td style='font-family:GE Inspira;font-size:12px;font-weight:bold;' align='center'>\r\n");
			sb.append("\t\t\t\t\t\t\t\tRRF QTO Metrics\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb
					.append("\t\t\t\t\t\t\t<td style='font-family:GE Inspira;font-size:12px;font-weight:bold;' align='center'>\r\n");
			sb.append("\t\t\t\t\t\t\t\tTarget\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t\t");

			int colIndex = 1;

			List<Map> dataList = new ArrayList();
			Map dataMap = null;
			int rowIndex = 0;
			while (rs.next() && rowIndex++ < 3) {
				dataMap = new HashMap();
				for (int i = 1; i <= size; i++) {
					dataMap.put(metaData.getColumnLabel(i), rs
							.getString(metaData.getColumnLabel(i)));
				}
				dataList.add(dataMap);
			}
			for (int i = dataList.size() - 1; i >= 0; i--) {
				sb
						.append("<td style='font-family:GE Inspira;font-size:12px;font-weight:bold;' align='center'>"
								+ dataList.get(i).get("FW") + "</td>");
			}

			sb.append("\r\n");
			sb.append("\t\t\t\t\t\t</tr>\r\n");
			sb.append("\t\t\t\t\t\t<tr>\r\n");
			sb
					.append("\t\t\t\t\t\t\t<td style='font-family:GE Inspira;font-size:12px;font-weight:bold;' align='left'>\r\n");
			sb.append("\t\t\t\t\t\t\t\tCSO\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t\t<td >\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t\t<td >\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t\t<td >\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t\t<td >\r\n");
			sb.append("\t\t\t\t\t\t\t</td>\r\n");
			sb.append("\t\t\t\t\t\t</tr>\r\n");
			sb.append("\t\t\t\t\t\t");

			for (int i = 3; i < 10; i++) {
				sb.append("<tr>");
				String title = metaData.getColumnLabel(i);
				// title = title.replaceAll("_","_<br>");
				sb
						.append("<td style='font-family:GE Inspira;font-size:12px;font-weight:bold;' align='right'>"
								+ title + "</td>");
				if ("P95".equals(title)) {
					sb
							.append("<td align='center'  style='font-family:GE Inspira;font-size:12px;'>90</td>");
				} else {
					sb
							.append("<td align='center' style='font-family:GE Inspira;font-size:12px;'>-</td>");
				}
				for (int j = dataList.size() - 1; j >= 0; j--) {
					sb
							.append("<td align='center' style='font-family:GE Inspira;font-size:12px;'>"
									+ dataList.get(j).get(title) + "</td>");
				}
				sb.append("</tr>");
			}

			rs.close();
			stmt.close();
			conn.close();

			sb.append("\r\n");
			sb.append("\t\t\t\t\t</table>\r\n");
			
			sb.append("<img width='1280' height='500' src='data:image/png;base64,"+request.getParameter("chart_data")+"'/>");
		} catch (Exception e) {
			e.printStackTrace();
		}
		try {
			email.setFrom("ibservice@163.com");
			email.setSubject("CSO Report");
			email.setHtmlMsg(sb.toString());
			email.addTo(request.getParameter("mail"));
			email.send();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * The doPost method of the servlet. <br>
	 * 
	 * This method is called when a form has its tag value method equals to
	 * post.
	 * 
	 * @param request
	 *            the request send by the client to the server
	 * @param response
	 *            the response send by the server to the client
	 * @throws ServletException
	 *             if an error occurred
	 * @throws IOException
	 *             if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
