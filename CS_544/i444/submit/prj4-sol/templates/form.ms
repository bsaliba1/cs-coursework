<form method={{form_method}}>
    {{#no_results}}
      <p></p>
      <ul>
        <li class="error">No results found.</li>
      </ul>
    {{/no_results}}
  {{#widgets}}
    {{>widget}}
  {{/widgets}}
  <label>&nbsp;</label><input type="submit" value={{button_label}}>
</form>
{{#search}}
  {{#sensor_types}}
    {{>type_table}}
  {{/sensor_types}}
  {{^sensor_types}}
    {{>sensor_table}}
  {{/sensor_types}}
{{/search}}
