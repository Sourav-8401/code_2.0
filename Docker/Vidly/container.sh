OUTPUT_FILE="docker_container_info.json"

# Start the JSON array
echo "[" > "$OUTPUT_FILE"

# Fetch container information and format it as JSON
docker ps -a --format '{"ID":"{{.ID}}", "Names":"{{.Names}}", "Status":"{{.Status}}", "Ports":"{{.Ports}}"}' | while read line; do
    echo "$line," >> "$OUTPUT_FILE"
done

# Remove the last comma and close the JSON array
sed -i '$ s/,$//' "$OUTPUT_FILE"  # This removes the last comma
echo "]" >> "$OUTPUT_FILE"

# Print a message indicating where the information is saved
echo "Docker container information has been saved to $OUTPUT_FILE"
