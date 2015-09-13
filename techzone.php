<?php
    // Include random movie function
    include 'random_movie.inc';
    
    $randomMovie = getRandomMovie();
?>


<!DOCTYPE html>
<html lang="en">
<head>
	<title>DVD Rentals</title>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="css/styles_main.css" type="text/css">
</head>
<body>
	<div id="content">

		<a href="index.php" id="headerBox">
			<h1 id="pageHeader">DVD Rentals</h1>
		</a>

		<div id="menuBar">
			<h3 id="menuHeader">Menu</h3>
			<a href="index.php">Home</a>
			<a href="join.php">Join</a>
			<a href="techzone.php">Tech Zone</a>
			<a href="moviezone.php">Movie Zone</a>
			<a href="contact.php">Contact</a>
		</div>

		<div id="rightColumn">
			<h2 id="newReleasesHeader"><a href="moviezone.php">New Releases</a></h2>

			<fieldset>
				<legend><?php echo $randomMovie['title'].' ('.$randomMovie['year'].')' ?> </legend>
					


					<span class="newReleaseHeading">Title: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['title']; ?></span>

					<span class="newReleaseHeading">Genre: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['genre_name']; ?></span>

					<span class="newReleaseHeading">Description: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['plot']; ?></span>

					<span class="newReleaseHeading">Image:</span>
					<img width="140" src="images/movie_images/<?php echo $randomMovie['thumbpath']; ?>" alt="<?php echo $randomMovie['title']; ?> (<?php echo $randomMovie['year']; ?>)" />

			</fieldset>
			
		</div>

		<div id="centerColumn">
			
			<div class="section">
				<h2 id="mainHeader">Tech Zone!</h2>

				<img src="images/meForWeb.jpg" alt="Dominic 'Nick' Browne" class="bodyImage"/>

				<p>Welcome to the tech zone. Looking for advice on all things IT realated? In this section our IT expert Nick will provide you with all the tips, tricks and hacks to make your Hardware and Software do exactly as you want it to!</p>
			</div>

			<div class="section">
                            <h2>Article 2: "What CMS Does Your Business Need"</h2>
                            <p>When planning for a web site one of the first questions that arise is how will I manage the site’s content? Should I develop the site from scratch and create my own management system or should I adopt an existing CMS? For the small to medium business that does not have dedicated IT personnel the answer is invariably to adopt an existing CMS.</p>
                            <p>The two basic applications common to all CMS are content creation/management and content delivery. The content/management application enables you to manage the creation, modification and removal of content from your website. The content delivery application uses and compiles that information to update the website. While many of the features of a CMS may differ, most include the basic functions of web based publishing, formatting, revision, indexing, search, and retrieval.</p>
                            <p>EContent Magazine estimates that there are roughly 2,000 CMS available (2007). Because of this the decision as to which one to choose may be overwhelming, particularly if one is inclined to initially compare the multitude of features of each one. A clear idea of what content and services the web site will be providing, both now and in the future, will enable the comparison and selection of a CMS based on functionality requirements and resource constraints.</p>
                            <p>For a typical small to medium business website we will be examining and comparing several alternative CMS. Five of the most popular CMS, which have been around for over eight years, are Prestashop, WordPress, Joomla, Drupal and Squarespace. The first four are open source software with readily available information and support from communities of developers and users. The benefits of open source software include being free to download and that it’s continually being developed and improved to support new technologies. Squarespace is proprietary software that is distributed as Software as a Service (SaaS).</p>
                            <h3>Prestashop</h3>
                            <p>Prestashop is an e-commerce CMS which is ideal for businesses whose sole venture is the sale of products both physical and virtual (Prestashop 2015). Prestashop can be downloaded for free and employed ‘straight out of the box’ with minimal CMS knowledge and experience. It has all the functionality required to set up and maintain your online store such as product management, customer management, search engine, shopping cart, checkout, payment, shipping, statistics reporting/analysis, marketing and security. Modules are available which can add advanced functionality such as language translation, support for alternative payment methods and slide shows of featured products. Alternatively, unwanted modules can be disabled to keep your online store simple and agile. Prestashop is also scalable to cater for the growth of your business. </p>
                            <h3>WordPress</h3>
                            <p>WordPress is possibly the best CMS for simple websites that share and distribute content such as news and review sites and blogging sites (WordPress 2015). Like Prestashop it is free and ready to use ‘out of the box’ and has a simple and intuitive interfaces for both the front and back ends. It comes packaged with a theme system which allows you to easily change the look of your site when you feel the need. According to Nikolay Gul (2014) there are over 3,000 additional themes are also readily available. Also like Prestashop, WordPress has a library of over 37,000 plugins (WordPress 2015) to add advanced functionality such as e-commerce and search engine optimisation. The downside to the availability of a huge number of plugins, however, is that a significant number may not have been built by competent developers which could potentially cause havoc to your site. </p>
                            <h3>Joomla</h3>
                            <p>Joomla is a similar but more advanced CMS to WordPress although it retains the same intuitive ease of use. It caters for more complex sites that contain greater and more diverse content then that generally found on WordPress sites whilst allowing for greater flexibility (Joomla 2015). Nikolay Gul  (2014) observes that Joomla is most commonly used as a community platform with advanced social networking functionality. </p>
                            <p>Comparatively, Joomla has a steeper learning curve than Prestashop or WordPress. However, once its structure and terminology are understood, its extensive suite of administration tools can be utilised. Also like Prestashop and WordPress, a large selection of add-ons to extend Joomla’s functionality is also available. Popular extensions include e-commerce engines, forum and messaging applications and data collection and reporting tools.</p>
                            <h3>Drupal</h3>
                            <p>Drupal is the most powerful CMS of the four examined due to its ability to categorise and organise complex content ‘out of the box’ (Drupal 2015). Unlike Prestashop, WordPress and Joomla, Drupal is extremely configurable and customisable to the extent that it could be considered to be more of a content management framework. Drupal will allow many site users to create content and to interact with each other. Nikolay Gul (2014) considers that Drupal provides incredible flexibility and is ideal for dynamic sites that require significant data organisation such as community sites with multiple users or large online stores. </p>
                            <p>Like the other CMS’s examined, the functionality of Drupal can be extended by add-on modules readily obtainable from within the Drupal community. Being more powerful comes with a price, however, as some degree of relevant knowledge of the software and technology that drives it is required. Support for a specific problem may be more difficult to find and you may have to ultimately pay someone to find a solution.</p>
                            <h3>Squarespace</h3>
                            <p>Squarespace differs from Prestashop, WordPress, Joomla and Drupal in that it is propriety software that requires a monthly service fee for its use and the hosting of your website on its remote servers. Support and functionality maintenance is also provided by the developer. Currently the monthly fee ranges from $8US per month to $36US per month depending on the level of functionality and volume of content required (Squarespace 2015). </p>
                            <p>Conforming to the KISS principle, Sqarespace is ideally suited to the novice or simple website developer where content is low in volume and static over time. For example: portfolios, wedding albums and musicians’ information sites. It also provides a simple to manage blogging platform. Being proprietary software the source code of this CMS is not accessible to the public and therefore lacks the availability of extensions developed by a community of users. A variety of extensions, however, are available from the developer. It uses a WYSIWYG interface that allows content to be viewed as it would appear on the website while it is being created and requires little to no knowledge of programming. Squarespace is scalable and easily adapts to an expanding business.</p>
                            <h3>Recommendations</h3>
                            <p>Selection of the best CMS for your website will ultimately be determined by your resource constraints (both financial and human) and required functionality (both immediate and projected). Prestashop, WordPress, Joomla and Drupal are free open source software whilst Squarespace is distributed as SaaS. The ongoing cost of maintaining the functionality of your website will depend on your degree of familiarity with its programming language and ability to obtain support from the community.</p>
                            <p>Should you be new to creating and maintaining a website, Prestashop, WordPress and Squarespace are recommended as prerequisite knowledge and experience is minimal and the learning curve is gentle. For those with limited time and/or who wish to avoid the potential hassles of working with open source software, then Squarespace would be my recommendation; provided you are comfortable with the ongoing service/hosting fees.</p>
                            <p>Joomla and Drupal are recommended should you wish to maintain a complex website that is characterised by a large volume of dynamic content and a large number of interactive users. Experience with programming will be a big benefit as the learning curve is relatively steep and the cost of paid support can be expensive.</p>
                            <h3>References</h3>
                            <p>Bob Doyle 2007, Compare and Contrast CMS, EContent Magazine, Viewed 13th September 2015 <br>&lt;http://www.econtentmag.com/Articles/Column/I-Column-Like-I-CM/Compare-and-Contrast-CMS-18966.htm&gt;</p>
                            <p>Prestashop home page 2015, Viewed 13th September 2015 <br>&lt;https://www.prestashop.com&gt;</p>
                            <p>WordPress 2015, About WordPress, Viewed 13thSeptember2015  <br>&lt;https://wordpress.org/about&gt;</p>
                            <p>Nikolay Gul 2014, WordPress Features, You Need IT, , Viewed 13th September 2015 &lt;http://www.youneeditall.com/cms/wordpress-features.html&gt;</p>
                            <p>WordPress 2015, Plug In Directory, Viewed 13thSeptember2015  <br>&lt;https://wordpress.org/plugins/browse/popular&gt;</p>
                            <p>Joomla 2015, About Joomla, Viewed 13thSeptember2015  <br>&lt;https://www.joomla.org/about-joomla.html&gt;</p>
                            <p>Nikolay Gul 2014, Joomla Content Management System (CMS) Overview, You Need IT, Viewed 13thSeptember2015  &lt;http://www.youneeditall.com/cms/joomla-features.html&gt;</p>
                            <p>Drupal 2015, The Drupal Overview, Viewed 13thSeptember2015  <br>&lt;https://www.drupal.org/getting-started/before/overview&gt;</p>
                            <p>Nikolay Gul 2014, Drupal Features, You Need IT,  Viewed 13thSeptember2015  <br>&lt;http://www.youneeditall.com/cms/drupal-features.html&gt;</p>
                            <p>Squarespace 2015 Fees, Viewed 13thSeptember2015  <br>&lt;http://www.squarespace.com&gt;</p>
                            
				<h2>Article 1: Apache2 vs IIS 7.5/8.5: A developers choice</h2>

				<p>As a web developer one of the first choices you’ll face is what web server software to use. The two most popular choices are the Aparche2 and Microsoft IIS. The choice that the web developer makes will have a profound impact on the future success of the website/web application in the areas of development costs, speed and portability. Therefore it is essential that the developer make the correct choice about which web server to utilize.</p>

				<h3>The host operating system</h3>

				<p>The host operating system plays a big role in this selection. While Apache2 is a cross platform web-server and can be run on a variety of host operating systems including GNU/Linux and Windows, IIS can only be deployed on Microsoft Windows based operating systems.</p>

				<p>If the developer is developing simply for personal use/education this consideration may not be very significant. However when the development becomes more serious the developer may be constrained to a certain platform by their employer and therefore will have to choose a web-server that best fits with their requirements.</p>

				<p>Certain work environments rely heavily on existing Microsoft servers such as active directory and integration with Microsoft SQL(MS-SQL) servers. IIS fits well in these environments and may be essential as it easily integrates with the existing technologies quit. However even in these environments Apache2 can still be used when configured correctly. </p>

				<p>Systems that use non-Microsoft based operating systems cannot run IIS without some kind of emulation or virtual host. While this might be appropriate for a specific goal it would usually only add a large amount of processing and memory overhead which results in reduced performance and an increased cost.</p>

				<h3>Supported Programming/Scripting languages</h3>

				<p>Both Microsoft IIS and Apache2 support a number of server side scripting languages including:</p>
				<ul>
					<li>PHP</li>
					<li>Pearl</li>
					<li>Python; and</li>
					<li>Ruby</li>
				</ul>

				<p>However Microsoft’s IIS natively supports proprietary scripting languages like its own asp.net language. While Apache2 does not support asp.net natively, asp.net code can be used with apache2 via a mono module, a cross platform open source implementation of the .net framework. (mod_mono, 2015)</p>

				<p>Ultimately IIS and Apache2 have a comparable support of different programming/scripting languages, however IIS 8 was designed with the .net framework in mind. Tools such as visual studio readily churn out Web Applications that run directly on IIS with very minimal configuration and tweaking and the two software packages work well together for rapid development as well as team based approaches.</p>

				<h3>Costs</h3>

				<p>Apache2 is free open source software that requires no-upfront licensing fees and can be used in a conjunction with a plethora of free and non-free software packages. This makes Apache2 is extremely flexible cost wise as it allows developers/businesses to set their own budget in regards to the software costs.</p>

				<p>Theoretically a full LAMP stack can be deployed with $0 licensing fees. That said there can still be costs involved in deploying a web project with 100% free software. This includes the costs of the computer hardware and internet provider fees (ISP). An alternative is to rent web-hosting from a 3rd party that allows use of their specialized hardware for a monthly fee, this can often be cheaper and offer better performance than hosting the web application on your own infrastructure.</p>

				<p>IIS on the other hand requires the developer/businesses to purchase a license for proprietary software from Microsoft which can be quite expensive. The Microsoft website reports that standard windows server 2012 license can cost as much as $882. (How to buy Windows Server 2012 R2, 2015)</p>

				<p>Similar to Apache2, in addition of the Windows license costs IIS developers have to then buy hardware to run their Windows operating system. The costs of deploying a Microsoft server are usually much higher than a free software stack because Windows requires more hard drive space to install and uses more memory.</p>

				<p>Supporting Software packages also add costs to the overall development. As mentioned in the programming languages section IIS is often used in conjunction with asp.net. While it is possible to write asp.net code without visual studio, this is rarely done as visual studio is optimized for deploying web applications directly to IIS with minimal configuration tweaks. However Visual Studio is another cost to consider being priced at $499 from Microsoft. (Visual Studio Professional 2013, 2015)</p>

				<h3>Hardware</h3>

				<p>Apache2 can be compiled to run on a variety of different hardware configurations including ARM and MIPS processors as well as a number of different host operating systems including Windows. This makes Apache2 incredibly versatile, a major benefit for a person’s who doesn’t have hardware that supports Windows operating systems but would still like to run/develop their own website. IIS on the other hand is bound to its host operating system and is thus restricted to IA-32 or x86-64 processors limiting the number of different hardware configurations that it supports.</p>

				<p>The windows operating system running IIS uses a considerable amount more disk space and ram than does a properly configured GNU/Linux system running Apache2. Using less disk space and ram can be beneficial for a number of reasons including:</p>

				<ul>
					<li>Running on portable hardware such as a smartphone;</li>
					<li>Running on legacy hardware;</li>
					<li>Making using of additional disk-space and ram to host additional websites/applications; and</li>
					<li>Making use of additional disk-space and ram to perform other, non-web related services.</li>
				</ul>

				<h3>Customization/Extensions</h3>

				<p>Both IIS and Apache2 have extensible functionality and support the creation of plugins and extensions. IIS supports the creation of extensions in C/C++ and C#/VB.net through Microsoft’s proprietary API. (IIS Extensions, 2015)</p>

				<p>Apache 2 also supports the creation of extensions called modules. These are usually written in C. (Developing modules for the Apache HTTP Server 2.4, 2015)</p>

				<p>One of the big advantages of Apache over IIS is that Apache, being open source allows developers who want to make changes or better understand the inner workings of the webserver are able to review/edit the source code of the webserver before compiling it. While this is not something the average user would ever need to worry about it does represent a far greater deal of flexibility.</p>

				<h3>Support/Community</h3>

				<p>Both IIS and Apache2 have a large community of users/developers willing to offer both free and paid support to those who are in need of assistance. As apache is currently the most popular webserver currently in use today there are simply far more enthusiasts willing to share tips and tricks with novice to experienced users in all areas of Apache, from configuration guides to the development of custom modules supporting specific user needs.</p>

				<p>IIS also has as large community of users/developers as well but as IIS is generally used by businesses there are less people willing to offer free advice regarding IIS and far less enthusiasm for web servers as a hobby.</p>

				<h3>Conclusion</h3>

				<p>While both IIS 7.5/8.5 and Apache2 offer a convenient and easy to configure way to deploy web projects Apache2 has many advantages over IIS to smaller-scale users who want to deliver the best performance from possibly less expensive hardware and software.</p>

				<p>IIS comes with many hidden costs such as the licensing of the windows platform, more expensive hardware/hosting costs and optional but highly recommended payed software like Visual Studio. </p>

				<p>Apache2 can be deployed with an entirely free software stack unlike IIS and can make use of less expensive hardware making it much more affordable for a small business, enthusiast or student. </p>

				<p>It is my recommendation that a novice stick with Apache2 unless they have a very specific reason to use IIS. Apache2 has a great community of enthusiasts to assist new users in configuration and maintenance and Apache2 works well for all the basic needs of a small scale user.</p>

				<h3>References</h3>

				<p>IIS Extensions, Viewed 3rd August 2015<br/>
				&lt;https://msdn.microsoft.com/en-us/library/hh943083%28v=vs.90%29.aspx&gt;</p>

				<p>Developing modules for the Apache HTTP Server 2.4, Viewed 3rd August 2015<br/>
				&lt;http://httpd.apache.org/docs/2.4/developer/modguide.html&gt;</p>

				<p>How to buy Windows Server 2012 R2, Viewed 3rd August 2015<br/>
				&lt;https://www.microsoft.com/en-au/server-cloud/products/windows-server-2012-r2/purchasing.aspx&gt;</p>

				<p>Visual Studio Professional 2013, Viewed 3rd August 2015<br/>
				&lt;http://www.microsoftstore.com/store/msusa/en_US/pdp/Visual-Studio-Professional-2013/productID.284832200&gt;</p>

				<p>mod_mono, Viewed 3rd August 2015<br/>
				&lt;http://www.mono-project.com/docs/web/mod_mono/>&gt;</p>

			</div>

			<footer>
				<div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>

		</div>



	</div>

	

</body>
</html>