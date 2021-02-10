/*  Question 1
    An inconsistency that I found in project 3 was that when finding for a sensor-data reading with a timestamp,
    the return value would have to match exactly or else it would return a 404. However, in project 2, when searching for sensor-data
    with a specified timestamp, if it did not match, then it would return next earliest timestamp. I can understand why this would make sense
    from a UI perspective; however, the logic for handeling these changes should be in the sensors.js file and shouldn't be handled in the sensors-ws.js file.
    We really shouldn't be manipulating the return value in the sensor-ws.js file.

    Question 2
    You would have to use a logic-less template and partials. You would have one partial for populating the name field, 
    one for the detail field and one for the contact field. Then you would call these partials from your template which. 
    If you wanted to make a change to the fields you want to include you could just remove or change that field within the partial object.
    ex.

    const template = `
        <employees>
        {{#employees}}
            <employee>
              {{>name}}
              {{>details}}
              {{>contacts}}
            </employee>
        {{/employees}}
        </employees>
    `
    const partial = {
        name: `<personName first={{name.first}} middle={{name.middle}} last={{name.last}}/>`,
        details: `<details joinDate={{details.joinDate}} birthDate={{details.birthDate}}/>`,
        contacts: `
        {{#contactInfos}}
            <contacts>
                <contactInfo>
                    <address type={{address.type}} line1={{address.line1}} city={{address.city}} state={{address.state}} zip={{address.zip}}/>
                </contactInfo>
                <contactInfo>
                    <phone type={{phone.type}} tel={{phone.tel}}/>
                </contactInfo>
            </contacts>
        {{/contactInfos}}
        `,
    };

    Question 3
    Pressing the 'place order' button probably sent a POST request, which inturn altered something server-side. This could be handled 1 of 2 ways:
        1. You could ensure that the place order process was idempotent
        2. You could redirect the user to a confirmation page when the user clicks the button, that way there is no option to click the button again

    Question 4
    - Use 'select' when the user can only select one choice and there are a large amount of option (typically > 4)
    - Use 'checkbox' when the user can select multiple choices and there are a small amount (typically < 4)
    - Use 'radio button' when the user can only one choice and there are a small amount (typically < 4)

    Question 5
    NOTE: domain is assumed to be 'salibapizza.com'
    - Allow listing of all the different types of pizza pies, like "thin crust", "thick crust", "regular", etc.
        * URL: http://salibapizza.com/pizza_types?crusts=true
        * HTTP Method: GET
        * HTTP or HTTPS: HTTP
        * Description of parameters and body: No body, parameters are what we wish to display. In
          this case we want to know all the types of crusts that saliba's pizza offers which is why we list that param as true
        * Caching Params: This is where you get a choice, do you want pure speed or do you want a small cache. If you want speed
          and you believe the user will want to know what the toppings are then you can store the entirety of the possible pizza options
          ex.
          types{
              crusts[...],
              toppings[...],
              sauces[...],
              cheeses[...]
          }
          So that subsequent calls will be very quick
        * Errors: If no pizza type params are provided this should return a 404
    - Allow listing of the different kinds of toppings like "sausage", "anchovies", "onions", etc.
        * URL: http://salibapizza.com/pizza_types?toppings=true
        * HTTP Method: GET
        * HTTP or HTTPS: HTTP
        * Description of parameters and body: No body, parameters are what we wish to display. In
          this case we want to know all the types of toppings that saliba's pizza offers which is why we list that param as true
        * Caching Params: Same as service 1 ^^^^
        * Errors: Same as service 1 ^^^^
    - Allow a customer to start building a pizza by specifying the type of pizza pie and the size.
        * URL: http://salibapizza.com/build_pizza
        * HTTP Method: GET
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: In this case we are obtaining all the possible options that the user has to build their pizza.
        ex.
          types{
              crusts[...],
              toppings[...],
              sauces[...],
              cheeses[...]
          }
           and creating an html form for them to fill out using a easy UI with checkboxes radio buttons and select options. We will submit this form when filled out
        * Caching Params: I would cache this 'types' object. Also cache the soon to be pizza_id and info.
        * Errors: If no fields are filled out this could cause an issue. 
    - Allow a customer to add an additional topping to a pizza being built.
        * URL: http://salibapizza.com/edit_pizza?id=[pizza_id]
        * HTTP Method: PATCH
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: the body of this patch will be the fields we wish to change
          {toppings: [pepperoni, cheese]};
          The params are the pizza_id for the pizza we would like to modify.
        * Caching Params: Cache the pizza_id and info.
        * Errors: The user could try to modify fields that are not supposed to be modified.
    - Allow a customer to remove a topping from a pizza being built. 
        * URL: http://salibapizza.com/edit_pizza?id=[pizza_id]
        * HTTP Method: PATCH
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: same as last service ^^^^
        * Caching Params: Same as last service ^^^^
        * Errors: Same as last service ^^^^
    - Allow a customer to entirely remove a pizza being built. 
        * URL: http://salibapizza.com/edit_pizza?id=[pizza_id]
        * HTTP Method: DELETE
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: No body, the params are the id for the pizza we would like to modify
        * Caching Params: Nothing to cache
        * Errors: Trying to delete a non-existant pizza. 404
    - Allow a customer to obtain details about a pizza being built.
        * URL: http://salibapizza.com/pizza_details?id=[pizza_id]
        * HTTP Method: GET
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: No body, params are the pizza_id for the pizza we would like to know the details of
        * Caching Params: Cache this pizza_id and details
        * Errors: Trying to view details for pizza that doesn't exist. 404
    - Allow a customer to view an image of the pizza.
        * URL: http://salibapizza.com/view_pizza?id=[pizza_id]
        * HTTP Method: GET
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: No body, params are the pizza_id for the pizza we'd like to view
        * Caching Params: Don't cache anything
        * Errors: Trying to view pizza that doesn't exist. 404
    - Dispatch the pizza for baking. Once dispatched, it should not be possible to modify the pizza.
        * URL: http://salibapizza.com/order_pizza?id=[pizza_id]
        * HTTP Method: PUT
        * HTTP or HTTPS: HTTPS
        * Description of parameters and body: No body, params are the pizza_id of the pizza we already created (assuming create pizza and order pizza are seperate steps).
          This will simply take the pizza_id and put it in the order queue.
        * Caching Params: Don't cache anything
        * Errors: Trying to order a previously deleted or non-existant pizza. 404

    Question 6
        I'm not sure exactly why he's running into this issue; however, it seems possible
        that the fact that the cache expiration is at midnight means that when individuals are trying to access the resource this compressed file is accessed
        however the contents can't be accessed because it is past he cache expiration, thus resulting in a blank page.
    
    Question 7
          a. False, you can keep a connection alive in order to continuosly make requests.
          b. True, this is because URL stands for uniform resource locator. It's basically an address for where to find a resource. 
             It would be impossible for two different resources to have the same url and not be the same resource.
          c. False, it should be loaded in the <input> section 
          d. False Javascript and CSS should always be placed in seperate files to seperate logic and styling
          e. False, cache time vs. catch fetch count are independent
*/