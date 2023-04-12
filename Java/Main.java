public class Main{
	public static void main(String[] args){
	    User user1 = new User();
	    user1.username = "TEST";
	    user1.setpass("&&&");
	    
	    // Printing Username
	    System.out.println("username: "+user1.getusr()+"\n"); 
	  
	    Post post1 = new Post();
	    post1.postId = 111;
	    post1.likes = 100;
	    post1.comments = 10;
        
        // Printing Post methods
	    System.out.println("PostID: "+post1.getpid());
	    System.out.println("PostLikes: "+post1.getpl());
	    System.out.println("PostComments: "+post1.getpc());
	    
	    // Liking and commenting
	    user1.likepost(post1);
	    user1.commentpost(post1);
	    
	    // Checking
	    System.out.println("\nPost Stats after like and comment");
	    System.out.println("PostLikes: "+post1.getpl());
	    System.out.println("PostComments: "+post1.getpc());
	}
}

class User{
	String username;
	private String password;
	public String getusr(){
	    return username;
	}
	public void setpass(String pass){
	    password = pass;
	}
	public void likepost(Post post){
	    post.likes++;
	}
	public void commentpost(Post post){
	    post.comments++;
	}
}

class Post{
	int postId;
	int likes;
	int comments;
	public int getpid(){
	    return this.postId;
	}
	public int getpl(){
	    return this.likes;
	}
	public int getpc(){
	    return this.comments;
	}
}
