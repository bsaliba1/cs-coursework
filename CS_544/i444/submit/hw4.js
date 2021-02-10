/* 

Baptiste Saliba
Assignment 4

 Question 1.
 One alternative would be to make sure that your POST is idempotent. That way if your user refreshes the page
 then a successive post request wouldn't actually change anything in the database. 

 Question 2.
      <table id="mary-kids-stats">
       <tr>
         <th>Name</th>
         <th>Age</th>
         <th>Height (meters)</th>
         <th>Weight (kg)</th>
       </tr>
       <tr class="kid anne">
         <td>Anne</td>
         <td>5</td>
         <td>1.08</td>
         <td>18.2</td>
       </tr>
       <tr class="kid jerry">
         <td>Jerry</td>
         <td>4</td>
         <td>0.95</td>
         <td>16.3</td>
       </tr>
       <tr class="kid john">
         <td>John</td>
         <td>7</td>
         <td>1.2</td>
         <td>23.1</td>
       </tr>
     </table>
    a) document.getElementById('mary-kids-stats').getElementByClassName('kid john').getElementsByTagName('td')[4]
    b) document.getElementById('mary-kids-stats').getElementByClassName('kid john').getElementsByTagName('td')[4].getAttribute()
    c) document.getElementById('mary-kids-stats').getElementsByTagName('tr').forEach(getElementsByTagName('td')[4])
    d) document.getElementById('mary-kids-stats').getElementByClassName('kid john').getElementsByTagName('td')

Question 3.
    a) $("#mary-kids-stats.kid_john:nth-child(4)");
    b) $("#mary-kids-stats.kid_john td[4]")
    c) $("#mary-kids-stats tr td[4]")
    d) $("#mary-kids-stats.kid_john td:even")

Question 4.
    Since the messages are received asynchronously you could just await that they all are received using await Promise.all().
    After all of the messages are received then we do `messages.forEach(m => insertContent(m.id, m.url));` At that point it will add
    them in the order which they are stored in 'messages'.

Question 5.
    There are many reasons that the call to Mary's webservice doesn't work.
    1. He is not calling the correct route
    2. The web service is not up and running
    3. It is only running locally on her machine so Bill would require the IP address to send the request to
    4. Mary has restriction set such that only super users can make a request to that route.
    etc.

Question 6.
    a) This won't work because you never binded this to the handleBlur function in the constructor
    
    b) This won't work because you never binded this to the handleBlur function in the constructor the same way it didn't work in part a) 

    c) This will work because you are using a lambda function which would bind this in handleBlur to the enclosing scope which
    int this case is the ReactComponent
    
Question 7.
    class AddrImageComponent extends React.Component {

      constructor(props) {
        super(props);
        this.state = {
          addr1: '', addr2: '', city: '', state: '', zip: ''
        };
      }

      onChange(event) {
        this.state[event.target.name] = event.target.value;
      }

      render() {
        const url = 'http://www.example.com?' +
          Object.keys(this.state).map((k)=>`k=${this.state.k}`).join('&');
        return (
          <form class="addr-image">
            <label for="addr1">Address Line 1:</label>
            <input id="addr1" value="this.state.addr1"
                   onChange={this.onChange}>
            <label for="addr2">Address Line 2:</label>
            <input id="addr2" value="this.state.addr2"
                   onChange={this.onChange}>
            <label for="city">City:</label>
            <input id="city" value="this.state.city"
                   onChange={this.onChange}>
            <label for="state">State:</label>
            <input id="state" value="this.state.state"
                   onChange={this.onChange}>
            <label for="zip">Zipcode:</label>
            <input id="zip" value="this.state.zip"
                   onChange={this.onChange}>
            <img src={url}>
          </form>
        );
      }
    }

    Critiques:
    1. By hardcoding url as 'http://www.example.com?...' you are making it less maintainable. If you wanted to change the domain
    then you would have to come back and manually change it.
    2. Adding new fields to the state data member would be a hastle because you'd have to add another <label> and <input> tag for that
    new component. It'd be better if you had a loop that would create all these components on the fly rather than hardcoding everything 
    and constantly repeating code 

    Bugs:
    1. Change: 'Object.keys(this.state).map((k)=>`k=${this.state.k}`)'  =>  'Object.keys(this.state).map((k)=>`${k}=${this.state.k}`)'
    2. Line missing in constructor: this.onChange = this.onChange.bind(this); 
    3. Everytime it says value="..." it should be replaced with value=`${...}`

    Question 8.
    The browser would know the image type because it would be specified in the http response MIME type header. It would specify image/gif, image/jpeg, image/png

    Question 9.
        a) False, it doesn't technically NEED to be encrypted but storing plaintext passwords is a big security liability because if
        someone were to hack your website they would easily obtain every users password.
        b) True, in order for HTML to be syntactically correct and valid it must be well-formed. This is because well-formedness is part
        of the html syntax
        c) True, a valid XML document is one that is not only well-formed, but also conforms to the grammar defined in its own DTD
        d) True, seeing as JSX uses a XML/HTML-like syntax, since HTML and XML both need well-formedness to be valid so does JSX
        e) False, ideally you would be able to using caching to minimize the amount of requests made to the server but to say that
        the application should not  make any requests to the server is unrealistic
*/
