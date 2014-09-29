package ibservice.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.mail.DefaultAuthenticator;
import org.apache.commons.mail.Email;
import org.apache.commons.mail.HtmlEmail;
import org.apache.commons.mail.SimpleEmail;

public class CopyOfSendMailServlet1 extends HttpServlet {

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HtmlEmail email = new HtmlEmail();
		email.setHostName("smtp.163.com");
		email.setSmtpPort(25);
		email.setAuthenticator(new DefaultAuthenticator("ibservice", "service123456"));
		StringBuilder sb=new StringBuilder(1024);
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","ta4_1","ta4_1");
			Statement stmt=conn.createStatement();
			String sql="select * from CSO where 1=1 ";
			if(request.getParameter("age_min")!=null&&request.getParameter("age_min").length()>0){
				sql+="and age>"+request.getParameter("age_min");
			}
			
			if(request.getParameter("age_max")!=null&&request.getParameter("age_max").length()>0){
				sql+="and age<"+request.getParameter("age_max");
			}
			
			if(request.getParameter("csonumber")!=null&&request.getParameter("csonumber").length()>0){
				sql+="and csonumber like '%"+request.getParameter("csonumber")+"%'";
			}
			
			if(request.getParameter("ownername")!=null&&request.getParameter("ownername").length()>0){
				sql+="and ownername like '%"+request.getParameter("ownername")+"%'";
			}
			ResultSet rs=stmt.executeQuery(sql);
			ResultSetMetaData metaData=rs.getMetaData();
			int size=metaData.getColumnCount();
			sb.append("<html><body><table border='1' cellpadding='0' cellspacing='0'>");
			sb.append("<tr>");
			for(int i=1;i<size+1;i++){
				sb.append("<td>"+metaData.getColumnLabel(i)+"</td>");
			}
			sb.append("</tr>");
			while(rs.next()){
				sb.append("<tr>");
				for(int i=1;i<size+1;i++){
					String value=rs.getString(metaData.getColumnLabel(i));
					value=value==null?"&nbsp;":value;
					sb.append("<td style='font-size:12px'>"+value+"</td>");
	    		}
				sb.append("</tr>");
			}
			sb.append("</table></body></html>");
			rs.close();
			stmt.close();
			conn.close();
		}catch(Exception e){
			e.printStackTrace();
		}
		sb.append("<img width='1280' height='500' src='data:image/png;base64,"+request.getParameter("chart_data")+"'/>");
		try{
			email.setFrom("ibservice@163.com");
			email.setSubject("CSO信息");
			email.setHtmlMsg(sb.toString());
			email.addTo(request.getParameter("mail"));
			email.send();
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
